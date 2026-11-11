#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=2e6+5;
int c,t,n,d;
int a[N];
struct node{
	int fi,se;
};
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
int xdsdg[65];
void write(int x){
	int tot=0;
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x==0){
		putchar('0');return;
	}
	while(x){
		xdsdg[++tot]=((x%10)^48);
		x/=10;
	}
	for(int i=tot;i;i--){
		putchar(xdsdg[i]);
	}
}
queue<node> p;
bool vis[N];
int tong[N];
void dfs(int s,int t,int lu){
	if(s==t){
		tong[lu]++;return;
	}
	bool f=0;
	for(int i=s+1;i<=t;i++){
//		cout<<s<<' '<<i<<' '<<a[i]-a[s]<<" "<<d<<'\n';
		if(a[i]-a[s]<=d){
			f=1;
			dfs(i,t,lu+1);
		}
	}
	if(!f)return;
}
bool check(int s,int t){
//	cout<<s<<' '<<t<<'\n';
	dfs(s,t,0);
	for(int i=1;i<=d;i++){
//		cout<<tong[i]<<"\n";
		if(tong[i]){
			if(tong[i]!=2)return 0;
			return 1;
		}
	}
	return 0;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read();t=read();
	while(t--){
		n=read();d=read();
		for(int i=1;i<=n;i++){
			a[i]=read();
		}
		int sum=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=1;k<=n;k++)tong[k]=0;
				
				if(check(i,j)){
//					cout<<i<<" "<<j<<'\n';
					++sum;
				}
			}
		}
		cout<<sum<<'\n';
	}
	return 0;
}
