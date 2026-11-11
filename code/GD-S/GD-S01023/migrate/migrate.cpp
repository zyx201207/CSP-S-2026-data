#include<bits/stdc++.h>
using namespace std;
const int N=1e4+10;
struct node{
	int times;
	int lon;
}res[N][N];
int c,t,n,m,cnta,cntb,ans,a[N],s[N][N];
queue <int> q;
void bfs(int st,int nd){
	q.push(st);
	int time=0;
	while(!q.empty()){
		int h=q.front();
		q.pop();
		if(h==nd){
			if(res[st][nd].lon==0){
				res[st][nd].lon=time;
				res[st][nd].times++;
			}
			else if(res[st][nd].lon==time){
				res[st][nd].times++;
			}
			if(cntb>1) cntb--;
			else{
				time++;
				cntb=cnta;
				cnta=0;
			}
			continue;
		}
		if(h>nd){
			if(cntb>1) cntb--;
			else{
				time++;
				cntb=cnta;
				cnta=0;
			}
			continue;
		}
		for(int i=1;i<=n;i++){
			if(s[h][i]==1){
				q.push(i);
				cnta++;
			}
		}
		if(cntb>1) cntb--;
		else{
			time++;
			cntb=cnta;
			cnta=0;
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=0;
		memset(a,0,sizeof(a));
		memset(s,0,sizeof(s));
		memset(res,0,sizeof(res));
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]<=m) s[i][j]=1;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				cnta=cntb=0;
				bfs(i,j);
				if(res[i][j].times==2) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
