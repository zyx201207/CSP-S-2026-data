#include<bits/stdc++.h>
using namespace std;
vector<int>b[50002];
int a[1001][1001],u,l,l1,f,ans,x,y,c,n,m,d,p,p1,k[502],w[500002];
bool bz[1001][1001];
void dfs(int sx,int sy){
	for(auto q:b[sx]){
		if(bz[sx][q]==true){
			p1+=a[sx][q];
			dfs(q,sy);
		}
	}
	if(sx==sy){
		ans+=p1;
		return;
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>p;
    for(int i=1;i<=m;i++)
    cin>>w[i];
    for(int i=1;i<=n;i++){
    	cin>>k[i];
    	l=0;
    	for(int j=1;j<=k[i];j++){
    		cin>>x>>y;
    		if(l==0)l=x,l1=y;
    		else {
    		    b[l].push_back(x);	
    		    a[l][x]=l1;
    		    bz[l][x]=true;
    		    l=x;
    		    l1=y;
			}
		}
	}
	for(int i=1;i<=p;i++){
		p1=0;
		ans=0;
		cin>>x>>y;
		ans+=w[x];
		dfs(x,y);
		ans+=w[y];
		cout<<ans<<endl;
	}
	return 0;
} 
