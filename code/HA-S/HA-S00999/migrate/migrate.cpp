#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+1;
int ID,T;
ll n,m;
ll a[N];
pair<ll,ll> f[N];
ll sum=0;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>ID>>T;
	while(T--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			f[i]={2e18+2,0};
		}
		f[1]={0,0};
		for(int i=2;i<=n;i++){
			for(int j=i-1;j>=1;j--){
				if(a[i]-a[j]<=m){
					if(f[j].first+1<f[i].first) f[i]={f[j].first+1,1};
					else if(f[j].first+1==f[i].first) f[i].second+=f[j].second;
				}else break;
			}
		}
		for(int i=1;i<=n;i++){
			if(f[i].second==2) sum++;
		}
		cout<<sum<<"\n";
	}
	return 0;
}

