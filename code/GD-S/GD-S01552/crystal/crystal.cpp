#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
ll n,m,a[N];
bool A=true;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i)A=false;
	}
	if(A){
		ll i=m,ans=0,k=1;
		while(i){
			if(i>=k*2)ans+=2,i-=k*2;
			else if(i>=k)ans++,i-=k;
			else break;
			k++;
		}
		cout<<ans+1;
	}else{
		sort(a+1,a+n+1);
		ll ans=1;
		for(int i=1;i<=n;i++){
			ll num=0,x=m;
			for(int j=1;j<=n;j++){
				if(x>=abs(a[j]-a[i])){
					num++;
					x-=abs(a[j]-a[i]);
				}
			}
			ans=max(ans,num);
		}
		cout<<ans;
	}
	return 0;
} 
