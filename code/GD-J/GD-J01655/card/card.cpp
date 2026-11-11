#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],w[300005],vis[500005],ans[300005];
bitset<300005>f;
int read(){
	int c,f=1,x=0;
	c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	return x*f;
}
void write(int x){
	if(x==0)return;
	if(x<0){putchar('-');x=-x;}
	write(x/10);
	putchar(x%10+'0');
}
void work1(){
	int l[300005];
	for(int i=1;i<=n;i++)l[a[i]]=i;
	for(int i=1;i<=m;i++){write(l[i]);putchar(' ');}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	bool flag=1;
	n=read();m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		if(i!=1&&a[i]>a[i-1])flag=0;
	}
	if(flag)return work1(),0;
	for(int i=1;i<=n;i++){
		memset(w,0,sizeof(w));
		memset(vis,0,sizeof(vis));
		f=0;
		for(int j=i;j<=n;j++){
			vis[j]=1;
			if(w[a[j]]){
				for(int k=w[a[j]];k<j;k++)vis[k]=0,w[a[k]]=0;
			}
			w[a[j]]=j;
		}
		for(int j=i;j<=n;j++){
			if(vis[j])f[a[j]]=1;
		}
		for(int j=1;j<=m;j++){
			ans[j]+=f[j];
		}
	}
	for(int i=1;i<=m;i++){write(ans[i]);putchar(' ');}
	return 0;
} 
