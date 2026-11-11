#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll len[509][509],c,n,m,d,q,w[500009],a,t,x,st,ed,ans;
struct ap{
	ll n1,n2;
};
vector<ap> ps[500009]; //zhan to line

	
	


int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=501;i++){
			memset(len[i],0x3f,sizeof(len[i]));
			len[i][i]=0;
	}
	for(int i=1;i<=m;i++){
			cin>>w[i];
	}
	for(int i=1;i<=n;i++){
			cin>>x;
			for(int j=1;j<=x;j++){
				cin>>a>>t;
				
				ps[a].push_back({i,t});
			}
			
	}
	for(int i=1;i<=m;i++){
		for(ap l1:ps[i]){
			for(ap l2:ps[i]){
				if(l1.n1!=l2.n1){
					len[l1.n1][l2.n1]=min(len[l1.n1][l2.n1],l2.n2+l1.n2);
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				len[i][j]=min(len[i][j],len[i][k]+len[k][j]);
			}
		}
	}
	
	for(int i=1;i<=q;i++){
		ans=1e18;
		cin>>st>>ed;
		for(ap l1:ps[st]){
			for(ap l2:ps[ed]){
				ans=min(ans,l1.n2+l2.n2+w[st]+w[ed]+len[l1.n1][l2.n1]);
		}	
		}
		cout<<ans<<'\n';
	}
	
	return 0;
}
