#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,cnt;
vector<int>vec[500005];
int vis[500005];
struct node{
	int uu,vv;
};

long long a[1005][1005],cz[1005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m+n;i++){
		for(int j=1;j<=m+n;j++){
			if(i!=j)a[i][j]=0x3f3f3f3f;
			else a[i][j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cin>>cz[i];
	}
	int pian,bool_pian=1;
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){	
			int w,v;//wÕ¾v¾àÀë
			cin>>w>>v;
			vec[w].push_back(m+i);
			vec[m+i].push_back(w);
			if(i==1&&j==1){
				pian=v;
			}else{
				if(pian!=v)bool_pian=0;
			}
			//cout<<w<<"zhantai"<<v<<"juli/n"; 
			a[w][m+i]=a[m+i][w]=v;	
		}
	}
	cout<<bool_pian<<endl;
//	}for(int i=1;i<=n+m;i++){
//		for(int j=1;j<=n+m;j++){
//			cout<<a[i][j]<<" ";
//		}cout<<endl;
//	}
//if(bool_pian==1){
//	while(q--){
//		int s,e;cin>>s>>e;
//		memset(vis,0,sizeof(vis));
//		queue<node>q;
//		q.push({s,0});
//		while(!q.empty()){
//			node now=q.front();q.pop();
//			vis[now.uu]=1;
//			if(now.uu==e){
//				cout<<pian*(now.vv)+cz[s]+cz[e];break;
//			}
//			for(int i=0;i<vec[now.uu].size();i++){
//				if(vis[vec[now.uu][i]]==0){
//					q.push({i,now.vv+1});
//				}
//			}
//		}
//	
//	
//	}		
//}
	for(int k=1;k<=n+m;k++){
		for(int i=1;i<=n+m;i++){
			for(int j=1;j<=n+m;j++){
				a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
			}
		}
	} 
	while(q--){
		int s,e;cin>>s>>e;
		cout<<a[s][e]+cz[s]+cz[e]<<endl;
	}
	
	return 0;
} 
