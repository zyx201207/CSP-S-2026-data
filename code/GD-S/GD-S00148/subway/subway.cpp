#include<bits/stdc++.h>
#define ll long long
#define x first
#define y second
#define PII pair<ll,ll>
#define pb push_back
#define lowbit(x) x&(-x)
using namespace std;
const int N=1e6+10;
const int INF=0x3f3f3f3f;
ll c,n,m,d,q,k;
ll st,ed;
ll w[N],a[505][20005],t[505][20005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	} 
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j]; 
		}
	}
	while(q--){
		cin>>st>>ed;
		ll ans=w[st]+w[ed];
		bool flag1=0,flag2=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k;j++){
				if(a[i][j]==st){
					if(!flag1){
						ans+=t[i][j];
						flag1=1;	
					}
				}if(a[i][j]==ed){
					if(!flag2){
						ans+=t[i][j];
						flag2=1;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
}

