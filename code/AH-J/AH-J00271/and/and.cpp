#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans;
bool used[200005];
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		x=x*10+ch-48;
		ch=getchar();
	}
	return x*f;
}
void dfs(int x,int s){
	if(x==m){
		ans=max(s,ans);
		return;
	}
	for(int i=1;i<=n;i++){
		if(used[i]==1)return;
		int ns=s&a[i];
		used[i]=1;
		dfs(x+1,ns);
		used[i]=0;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++){
		used[i]=1;
		dfs(1,a[i]);
		used[i]=0;
	}
	cout<<ans<<endl;
	return 0;
}
