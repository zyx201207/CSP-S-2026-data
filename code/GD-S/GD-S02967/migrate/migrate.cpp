#include<bits/stdc++.h>
using namespace std;
int read(){
	int x=0,fg=1;char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-') fg=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*fg;
}
int c,t,n,d,a[2000001],b[2000001],f[2000001],ans,cnt;
bool check(int x,int y){
	for(int i=x+1;i<=y;i++){
		if(a[i]-a[i-1]>d) return false;
	}
	return true;
}
int ff(int x,int y){
	memset(f,0,sizeof(f));
	for(int i=x+1;i<=y;i++){
		f[i]=f[i-1]+1;
		for(int j=i-1;j>=x;j--){
			if(a[i]-a[j]<=d) f[i]=min(f[i],f[j]+1);
		}
	}
	return f[y];
}
void dfs(int x,int y,int l,int z){
	if(l>z) return ;
	if(x==y){
		cnt++;
		return ;
	}
	for(int i=x+1;i<=y;i++){
		if(a[i]-a[x]<=d) dfs(i,y,l+1,z);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read();t=read();
	while(t--){
		ans=0;
		n=read();d=read();
		for(int i=1;i<=n;i++) a[i]=read();
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(check(i,j)){
					int tmp=ff(i,j);
					cnt=0;
					dfs(i,j,0,tmp);
					if(cnt==2) ans++;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
