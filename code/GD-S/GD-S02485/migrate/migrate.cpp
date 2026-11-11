#include<bits/stdc++.h>
using namespace std;
#define int long long
int read();
void write(int x);
int c,t;
int const D=2e6+50;
int x[D];
int n,d;
int u[D];
int ans;
void dfs1(int l,int r){
	int ll=l;
	u[l]++;
	for(int i=l;i<=r;i++){
		while(i<=r&&x[i]-x[ll]<=d)i++;
		u[i-1]++;
		ll=i;
	}
}
void dfs2(int r,int l){
	int rr=r;
	u[rr]++;
	for(int i=r;i>=l;i--){
		while(i>=l&&x[rr]-x[i]<=d)i--;
		u[i+1]++;
		rr=i;
	}
}
void work(int l,int r){
	for(int i=l;i<=r;i++){
		for(int j=i+3;j<=r;j++){
			for(int k=0;k<=n;k++)u[k]=0;
			dfs1(i,j);
			dfs2(j,i);
			bool flag=true;
			for(int k=0;k<=n;k++){
				if(u[k]){
					if(u[k]!=2){
						flag=false;
						break;
					}
				}
			}
			if(flag==false){
				ans++;
			}
		}
	}
}
void merge(int l,int r){
	int ll=l;
	if(x[r]-x[l]<=d){
		return;
	}
	for(int i=l+1;i<=r;i++){
		if(x[i]-x[i-1]>d){
			if(i-ll>=4){
				work(ll,i-1);
			}
			ll=i;
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		n=read(),d=read();
		for(int i=1;i<=n;i++){
			x[i]=read();
		}
		x[n+1]=1e18+50;
		ans=0;
		merge(1,n+1);
		write(ans);
		putchar('\n');
	}
	return 0;
}
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-f;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
void write(int x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
