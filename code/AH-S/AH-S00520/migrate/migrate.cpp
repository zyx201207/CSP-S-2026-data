#include<bits/stdc++.h>
using namespace std;
#define int long long
int read(){
	int s=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		s=s*10+ch-'0';
		ch=getchar();
	}
	return s*f;
}
void write(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>=10)write(x/10);
	putchar(x%10+'0');
}
const int N=2e6+10;
int c,T,d,n,a[N],f[N],g[N],ans,sum[N];
int query2(int x,int y,int z){
	int l=x,r=y;
	while(l<r){
		int mid=(l+r+1)>>1;
		if(f[mid]<=f[z]-1)l=mid;
		else r=mid-1;
	}
	return l;
}
int query1(int x,int y,int z){
	int l=x,r=y;
	while(l<r){
		int mid=(l+r)>>1;
		if(f[mid]>=f[z]-1)r=mid;
		else l=mid+1;
	}
	return l;
}
int l[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),T=read();
	while(T--){
		ans=0;
		n=read(),d=read();
		memset(l,0,sizeof(l));
		for(int i=1;i<=n;i++)a[i]=read();
		for(int i=1,j=1;i<=n;i++){
			while(a[i]-a[j]>d)j++;
			l[i]=i-j;
		}
		for(int i=1;i<=n;i++){
			f[i]=0;g[i]=1;sum[i]=1,sum[i-1]=0;
			for(int j=i+1;j<=n;j++){
				if(l[j]==0)break;
				f[j]=f[j-l[j]]+1;
				int rg=query1(j-l[j],j-1,j),lg=query2(j-l[j],j-1,j);
				g[j]=sum[lg]-sum[rg-1];
				if(g[j]==2){
					ans++;
				}
				sum[j]=sum[j-1]+g[j];
			}
		}
		write(ans);
		putchar('\n');
	}
	return 0;
}
