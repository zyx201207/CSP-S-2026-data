#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1e4+5;
ll m,n,d,c,q,r,x,y,ans=0,num=0,sum=N;
ll w[N],k[N],a[N][N],t[N][N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(ll i=0;i<m;i++){
		cin>>w[i];
	}
	for(ll i=0;i<n;i++){
		cin>>k[i];
		for(ll j=0;j<k[i];j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	while(q--){
		ans=0;
		cin>>x>>y;
		ans+=w[x-1]+w[y-1];
		for(ll i=0;i<n;i++){
			ll f1=0;
			for(ll j=0;j<k[i];j++){
				if(a[i][j]==x) f1=j;
				if(a[i][j]==y&&f1){
					for(;f1<j;f1++){
						num+=a[i][f1];
					}
				}
				
			}
			sum=min(sum,num);
		}
		ans+=sum;
		cout<<ans<<'\n';
	}
	return 0;
} 
