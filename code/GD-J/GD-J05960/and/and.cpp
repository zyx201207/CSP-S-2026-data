#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[2000005][35],c[35],vis[20000005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ll i=0;i<n;i++){
		ll x,j=0;
		cin>>x;
		while(x){
			a[i][j]=(x&1);
			c[j]+=(x&1);
			x>>=1;
			j++;
		}
	}
//	for(ll i=30;i>=0;i--){
//		cout<<c[i]<<endl;
//	}
	ll cnt=0;
	for(ll i=30;i>=0;i--){
		cnt<<=1;
//		cout<<c[i]<<" "<<cnt<<endl;
		if(c[i]>=m){
			cnt+=1;
			for(ll j=0;j<n;j++){
				if(a[j][i]==0&&!vis[j]){
					for(ll k=i;k>=0;k--){
						c[k]-=a[j][k];
						a[j][k]=0;
//						cout<<k<<"::"<<c[k]<<endl;
					}
					vis[j]=1;
				}
			}
		}
	}
	cout<<cnt;
	return 0;
}
