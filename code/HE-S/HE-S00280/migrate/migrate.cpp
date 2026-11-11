#include<bits/stdc++.h>
using namespace std;
const int N=5e3+5;
int read(){
	int x=0,f=1;
	char c=getchar();
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
void write(int x){
	if(x>=10){
		write(x/10);
	}
	putchar(x%10+'0');
}
int c,t,n,d;
int x[N];
int cnt=0;
int mina=0x3f3f3f3f;
void dfs(int u,int v,int p,int l){
//	cout<<mina<<' ';
	if(p==v){
//		cout<<633;
		if(l==mina){
			cnt++;
		}
		else if(l<mina){
			mina=l;
			cnt=1;
		}
		return;
	}
	for(int i=p+1;i<=v;i++){
//		cout<<i;
		if(x[i]-x[p]<=d){
			dfs(u,v,i,l+1);
		}
	}
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),t=read();
	while(t--){
		n=read();
		d=read();
		for(int i=1;i<=n;i++){
			x[i]=read();
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				cnt=0;
				mina=0x3f3f3f3f;
				dfs(i,j,i,0);
				if(cnt==2) ans++;
			}
		}
		write(ans);
		putchar('\n');
	}
	return 0;
}
//0 2
//4 2
//1 2 3 4
//5 2
//1 2 3 4 5
//0 2
//5 3
//-2 -1 0 1 2
//6 2
//-4 -3 -2 -1 3 6
