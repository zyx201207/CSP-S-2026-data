#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10,INF=LLONG_MAX,P=13331;
int read(){
	int x=0,f=1;
	char c=getchar();
	while('0'>c||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while('0'<=c&&c<='9')x=x*10+c-'0',c=getchar();
	return x*f;
}
void write(int x){
	if(x<0)putchar('-'),x=-x;
	if(x<10)putchar(x+'0');
	else write(x/10),putchar(x%10+'0');
}
int n,m,a[N],pre[N],col[N],ans[N];
bool vis[N],f=1;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		if(a[i-1]>a[i])f=0;
	}
	if(f){
		for(int i=1;i<=n;i++)ans[a[i]]++;
		for(int i=1;i<=m;i++)ans[i]+=ans[i-1];
		for(int i=1;i<=m;i++)write(ans[i]),putchar(' '); 
	}
	else{
		for(int i=1;i<=n;i++){
		memset(pre,0,sizeof pre);
		memset(col,0,sizeof col);
		memset(vis,0,sizeof vis);
		for(int j=i;j<=n;j++){
			if(pre[a[j]]){
				for(int k=pre[a[j]];k<j;k++){
					if(!vis[k]){
						col[a[k]]--;
						if(pre[a[k]]==k)pre[a[k]]=0;
						vis[k]=1;
					}
				}
			}
			col[a[j]]++;
			pre[a[j]]=j;
		}
			for(int j=1;j<=m;j++)ans[j]+=(col[j]>0);
		}
		for(int i=1;i<=m;i++)write(ans[i]),putchar(' ');
	}
//	for(int j=1;j<=n;j++){
//		if(pre[a[j]])for(int k=pre[a[j]];k<j;k++)col[a[k]]--;
//		col[a[j]]++;
//		pre[a[j]]=j;
//		for(int k=1;k<=m;k++)cout<<col[k]<<" ";
//		cout<<"\n";
//	}
}
