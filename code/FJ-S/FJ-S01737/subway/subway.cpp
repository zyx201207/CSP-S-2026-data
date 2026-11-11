#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500005],k;
int a,t;
int x,y;
/*int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*f;
}
void dfs(int u,int v){
	for(int i=0;i<m[u].size();i++){
		
	}
}*/
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
			cin>>a>>t;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		cout<<w[x]+w[y]<<endl;
	}
} 
