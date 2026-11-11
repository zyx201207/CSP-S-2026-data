#include<bits/stdc++.h>
using namespace std;
long long n,m,c,d,p,r,l,w[10000],t[1000][1090];
int ans=1e2;
bool k[1000][1000];
void dfs(int st,int ed,int cnt){
	if(st==ed){
		ans=min(ans,cnt);
		return;
	}
	for(int i=1;i<=m;i++){
		if(t[st][i]==0||k[st][i]==1)continue;
		k[st][i]=1;
		if(i==ed)cnt-=t[i][i];
		dfs(i,ed,t[st][i]+cnt+t[i][i]);
		k[st][i]=0;
	}
}


int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	if(c==0)c++;
	for(int e=0;e<c;e++){
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
	 	for(int j=1;j<=k;j++){
			cin>>r>>l;
			t[i][r]=l;
		}
	}
	for(int j=1;j<=p;j++){
		int st,ed;
		cin>>st>>ed;
		dfs(st,ed,w[st]+w[ed]+t[st][st]);
		cout<<ans<<endl;
		ans=1e2;
	}
}
	return 0; 
} 

