#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=5e5+100;
ll n,m,a[N],A=0,B=0,ans=0,sum=0,cha[N],k,b[N],tot=1,zero=0;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	std::cin.tie(nullptr)->std::ios::sync_with_stdio(false);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i){
			A=1;
		}
	}
	sort(a+1,a+1+n);
	if(n==1){
		cout<<0<<'\n';
		return 0;
	}
	if(m==0){
		sum=1;
		for(ll i=2;i<=n;i++){
			if(a[i]==a[i-1]){
				sum++;
			}
			else{
				ans=max(ans,sum);
				sum=1;
			}
		}
		cout<<ans<<'\n';
		return 0;
	}
	k=1;
	for(ll i=2;i<=n;i++){
		k++;
		if(a[i]!=a[i-1]){
			cha[i]=cha[i-1]+(k-1)*(a[i]-a[i-1]);
			sum=a[i];
			while(cha[i]>m&&k>=1&&tot<=i){
				k--;
				cha[i]=max(zero,cha[i]-(a[i]-a[tot]));
				tot++;
			}
			if(cha[i]>m){
				cha[i]=0;
				k=0;
				tot=i;
			}
		}
		else{
			cha[i]=cha[i-1];
		}
		ans=max(ans,k);
	}
	cout<<ans<<'\n';
	return 0;
}
/*
Oct31==Dec25?
10 5 
1 3 6 6 100 100 100 100 100 101
*/
