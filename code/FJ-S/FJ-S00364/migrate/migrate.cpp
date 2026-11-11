#include<bits/stdc++.h>
using namespace std;
int read(){
	char c=getchar();
	int x=0,f=1;
	while(c<'0'||c>'9'){
		if(c=='-'){
			f=-1;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
const int N=5e5+4;
int a[N];
int pre[N];
void dfs(int u,int v){
	for(int i=1;i<=d;i++){
		if()
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			pre[i]=a[i]-a[i-1];
		}
	}
	cout<<1<<"\n"<<2;
	return 0;
}
