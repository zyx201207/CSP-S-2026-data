#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+10,MAXM=3e5+10;
int n,m,a[MAXN];
int f[MAXN],ans[MAXN];
int c[MAXM];
int st[MAXN],top;
queue<int> q;
bool v[MAXM];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		f[i]=c[a[i]];
		c[a[i]]=i;
	}
	if(n<=5000){
		for(int i=1;i<=n;i++){
			memset(v,false,sizeof v);
			top=0;
			for(int j=i;j<=n;j++){
				if(v[a[j]]==0){
					v[a[j]]=1;
					st[++top]=a[j];
				}else{
					while(st[top]!=a[j]) v[st[top--]]=0;
				}
			}
			for(int j=1;j<=top;j++) ans[st[j]]++;
		}
	}else{
		for(int i=1;i<=n;i++){
			if(a[i]!=a[i+1]) ans[a[i]]=i;
		}
	}
	for(int i=1;i<=m;i++) printf("%d ",ans[i]);
	return 0;
} 
