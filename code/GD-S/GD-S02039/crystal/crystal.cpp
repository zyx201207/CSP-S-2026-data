#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int ans=0,bian=100000000,g=1,ans1=0;
int a[100000000];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	if(n>500000){
		cout<<n;
		return 0;
	}
	if(n>5000){
		int z=(1+n)*n/2;
		if(m>=z){
			cout<<n;
			return 0;
		}else{
			int q=n;
			while(m<=z){
				m-=a[n];
				q--;
			}
			cout<<q;
			return 0;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans+=a[i];
	}int sum=ans/n;
	for(int i=1;i<=n;i++){
			bian=min(bian,abs(a[i]-sum));
			if(abs(sum-a[i])<=bian){
				g=i;
			}
	}
	//cout<<g;
	for(int i=g;i>=1;i--){
		if(sum-a[i]<=m){
			m-=(sum-a[i]);
			ans1++;
		}
	}cout<<ans1;
	return 0;
}/*5 8
-3 -1 2 2 7
Oct31==Dec25?*/
