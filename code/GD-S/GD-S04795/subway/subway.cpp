#include<bits/stdc++.h>
using namespace std;
const int MAXN=20012;
long long c,n,m,d,q;
int at[MAXN][MAXN],ct[MAXN],w[MAXN];
bool vis[MAXN];
int to(int x,int y){
	if(at[x][y]>0) return at[x][y];
	vis[x]=true;
	vis[y]=true;
	int ans=0;
	for(int i=1;i<=m;i++)
	if(!(i==x || i==y) && vis[i]==false){
		vis[i]=true;
		int t=to(x,i)+to(i,y);
		if(ans) ans=min(t,ans);
		else ans=t;
	}
	return ans;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		int sd[k]={};
		for(int j=1;j<=k;j++){
			cin>>sd[j];
			cin>>ct[sd[j]];
			int t=j-1;
			while (t>=1){
				at[sd[t]][sd[j]]=ct[sd[t]]+ct[sd[j]];
				at[sd[j]][sd[t]]=at[sd[t]][sd[j]];
				t--;
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		int vis[MAXN]={false};
		cout<<to(x,y)+w[x]+w[y]<<endl;
	}
} 
