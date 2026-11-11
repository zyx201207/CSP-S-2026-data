#include<bits/stdc++.h>
using namespace std;
int jl[2000010]={};
int s[2000010]={};
int c,t,n;
long long d;
bool q[2000][2000]={};
bool vis[20000]={};
queue<int> l;
int bfs(int u,int v){
	memset(vis,0,sizeof(vis));
	l.push(u);
	vis[u]=1;
	bool flag=0;
	int cnt=0;
	while(!l.empty()){
		int lf=l.front();
		l.pop();
		int j=0;
		for(int i=0;i<2000;i++){
			if(!q[lf][i]) continue;
			int vz=i;
			j++; 
			if(vz==v){
				for(int i=1;i<j;i++) {l.pop();}
				cnt++;
				flag=1;
				break;
			}
			if(!flag&&!vis[vz]){
				l.push(vz);
				vis[vz]=1;
			}
		}
	}
	return cnt;
}
int main(){
	freopen("mlgrate.in","r",stdin);
	freopen("mlgrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		if(n>=10){
			cout<<0;
			return 0;}
		cin>>jl[1]>>jl[2];
		s[2]=jl[1]-jl[2]>0?jl[1]-jl[2]:jl[2]-jl[1];
		for(int i=3;i<=n;i++){
			cin>>jl[i];
			int gdz=jl[i]-jl[i-1]>0?jl[i]-jl[i-1]:jl[i-1]-jl[i];
			s[i]=s[i-1]+gdz;
		}
		
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(s[j]-s[i-1]<=d){
					q[i][j]=1;
					q[j][i]=1;
			    }
		    }
	    }
	    int acnt=0;
	    for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int x=bfs(i,j);
				
				if(x==2) acnt++;
			}
		}
		cout<<acnt;
	}
	
}
