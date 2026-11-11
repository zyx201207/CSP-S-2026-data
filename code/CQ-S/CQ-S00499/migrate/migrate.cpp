#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e6+5;
int C,T,n,l[N],r[N],t[N];
ll d,a[N];
ll read(){
	ll s=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		s=s*10+ch-'0';
		ch=getchar();
	}
	return s*f;
}   
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d %d",&C,&T);
	while(T--){
		scanf("%d %lld",&n,&d);
		int p=1;
		for(int i=1;i<=n;i++){
			a[i]=read();
			while(a[i]-a[p]>d)p++;
			l[i]=p;
		}
		p=n;
		for(int i=n;i>=1;i--){
			while(a[p]-a[i]>d)p--;
			r[i]=p;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int x=i,c=0;
				while(x<j){
					if(r[x]==x)break;
					t[++c]=x;
					x=r[x];
				}
				t[++c]=j;
				if(x<j)continue;
				x=j;
				int flag=0;
				for(int k=c;k>=1;k--){
					if(t[k]!=x){
						if(!flag&&abs(t[k]-x)==1)flag=1;
						else flag=-1;
					}
					x=max(i,l[x]);
				}
				// printf("%d %d:",i,j);
				// for(int k=1;k<=c;k++)printf("%d ",t[k]);
				// printf("\n");
				if(flag>0)ans++;
				// if(flag>0)printf("%d %d\n",i,j);
				// printf("%d ",flag);
			}
			// printf("\n");
		}
		printf("%d\n",ans);
	}
	return 0;
}