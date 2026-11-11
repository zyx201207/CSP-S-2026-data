#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+5;
int c,n,m,d,q,x,y,ans;
int w[MAXN],vuv[MAXN];
int vis[MAXN],vis2[MAXN],quy[MAXN];
int t[MAXN][505];
struct node{
	int w,t;
};
queue<node>qu;
void bfs(int s){
	for(int i=1;i<=s;i++){
		int xxx=qu.front().w,ttt=qu.front().t;
		vis[xxx]=ttt;
		qu.pop();
		if(xxx==y){
			ans=min(ans,ttt);
			continue;
		}
		for(int k=1;k<=vuv[0];k++){ //Õ¾ 
			for(int j=1;j<=n;j++){//Ïß
				if((t[j][vuv[k]]>0&&t[j][xxx]>0)&&vuv[k]!=xxx&&ttt+t[j][xxx]+t[j][vuv[k]]<vis[vuv[k]]){
					qu.push({vuv[k],ttt+t[j][xxx]+t[j][vuv[k]]});
				}
			}
		}
	}
	if(!qu.empty()){
		bfs(qu.size());
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
    	cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int aaa,ttt;
			cin>>aaa>>ttt;
			t[i][aaa]=ttt;
			quy[aaa]++;
			if(quy[aaa]>=2&&vis2[aaa]==0){
				vuv[0]++;
				vuv[vuv[0]]=aaa;
				vis2[aaa]=1;
			}
		}
	}
	vuv[0]+=2;
	for(int i=1;i<=q;i++){
		for(int j=1;j<=m;j++) vis[j]=1e9;
		cin>>x>>y;
		ans=1e9;
		qu.push({x,0});
		vuv[vuv[0]-1]=x;
		vuv[vuv[0]]=y;
		bfs(1);
		cout<<ans+w[x]+w[y]<<endl;
	}
	return 0;
}
