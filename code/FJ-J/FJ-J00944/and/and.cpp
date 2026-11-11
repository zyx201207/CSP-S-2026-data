#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
	char c=getchar();
	int x=0,f=1;
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	return x*f;
}
inline void write(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9) write(x/10);
	putchar(x%10^48);
	return;
}
int n,a[200005],b[25],m,maxx=INT_MIN;
bool pd[25];
void dfs(int x,int k){
	if(x>m){
		int ans=a[b[1]];
		for(int i=1;i<=m;i++){
			ans&=a[b[i]];
		}
	//	cout<<ans<<endl;
		maxx=max(maxx,ans);
		return;
	}
	for(int i=k;i<=n;i++){
		if(pd[i]==false){
			b[x]=i;
			pd[i]=true;
			dfs(x+1,i);
			pd[i]=false;
		}
	}
	return;
}

signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	if(n<=20){
		dfs(1,1);	
		write(maxx);
	}else if(n<=2000){
		if(m==1){
			for(int i=1;i<=n;i++) maxx=max(maxx,a[i]);
			write(maxx);
		}else if(m==n){
			int ans=a[1];
			for(int i=1;i<=n;i++) ans&=a[i];
			write(ans);
		}else if(m==2){
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					int ans=a[i]&a[j];
					maxx=max(maxx,ans);
				}
			}
			write(maxx);
		}
	}else{
		for(int i=1;i<=n;i++){
			int ans;
			if(i==1) ans=a[2];
			else ans=a[1];
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				ans&=a[j];
			}
			maxx=max(maxx,ans);
		}
		write(maxx);
	}
	return 0;
}
