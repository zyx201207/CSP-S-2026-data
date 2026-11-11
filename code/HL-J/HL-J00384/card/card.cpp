#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=500005;
ll a[N];
int cnt[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
	}if(n<=5000&&m<=3000){
		bool f=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j)continue;
				else {
					if(a[i]==a[j]){
						f=1;
					}
				}
			}
		}
		if(f==0){
			int tot[100005]={};
			for(int i=1;i<=n;i++){
				for(int j=i;j<=n;j++){
					tot[a[i]]++;
				}
			}
			for(int i=n;i>=1;i--){
				cout<<tot[i]<<" ";
			}return 0;
		}		
	}
		bool vis[100005]={};
		
		for(ll i=1;i<=n;i++){
			ll l=1;
			for(ll j=i;j<=n;j++){
				if(vis[j]==1){
					l=j;
				}
				else vis[j]=1;
			}
			for(int i=l;i<=n;i++){
				cnt[a[i]]++;
				l=1;
			}cout<<endl;
		}

		for(int i=1;i<=m;i++)cout<<cnt[a[i]]<<" ";
		return 0;
}
