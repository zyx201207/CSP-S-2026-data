#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,p,cot[500005],mapp[500005][25],xt[505][505],dist[505],vis[505];//mapp[站台编号][所对线路]=花费时间 
long long tmp,x1,y1,fro,to,inf,bj;
void dijk(int st){
	for(int i=1;i<=n+2;i++){dist[i]=inf;}
	dist[st]=0;
	queue<int> q;
	q.push(st);
	while(!q.empty()){
		long long tmp=q.front(),len=inf;
		q.pop();
		for(int i=1;i<=n+2;i++){
			if(xt[i][tmp]!=inf && i!=tmp && dist[i]>dist[tmp]+xt[i][tmp]){
				bj=i;
				len=xt[i][tmp];
				//cout<<"bj:"<<bj<<" len:"<<len<<" ";
				dist[bj]=min(len+dist[tmp],dist[bj]);
				q.push(bj);
			}
		}
		//cout<<endl;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	inf=9223372036854775807;
	for(int i=1;i<=502;i++){
		for(int j=1;j<=502;j++) xt[i][j]=inf;
	}
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++) cin>>cot[i];
	for(int i=1;i<=n;i++){
		cin>>tmp;
		mapp[i][0]=tmp;
		for(int j=1;j<=tmp;j++){
			cin>>x1>>y1;
			mapp[x1][i]=y1;
		}
//		for(int j=1;j<=7;j++){
//			for(int k=1;k<=7;k++) cout<<mapp[j][k]<<" ";
//			cout<<endl;
//		}		
	}
	for(int i=1;i<=m;i++){
		for(int k=1;k<=mapp[i][0];k++){
			for(int j=1;j<=mapp[i][0];j++){
				if(k!=j && mapp[i][k]!=0 && mapp[i][j]!=0) xt[k][j]=min(xt[k][j],mapp[i][k]+mapp[i][j]);
			}
		}
	}
		
	for(int ts=1;ts<=p;ts++){
		cin>>fro>>to;
//		for(int i=1;i<=n+2;i++){
//			for(int j=1;j<=n+2;j++){
//				cout<<(xt[i][j]==inf?-1:xt[i][j])<<" ";
//			}
//			cout<<endl;
//		}
		for(int i=1;i<=20;i++){
			if(mapp[fro][i]!=0) xt[n+1][i]=mapp[fro][i],xt[i][n+1]=mapp[fro][i];
			if(mapp[to][i]!=0) xt[n+2][i]=mapp[to][i],xt[i][n+2]=mapp[to][i];
		}
//		for(int i=1;i<=n+2;i++){
//			for(int j=1;j<=n+2;j++){
//				cout<<(xt[i][j]==inf?-1:xt[i][j])<<" ";
//			}
//			cout<<endl;
//		}
		dijk(n+1);
		//for(int i=1;i<=n+2;i++) cout<<dist[i]<<" ";
		//cout<<endl;
		cout<<dist[n+2]+cot[fro]+cot[to]<<endl;
	}
}
