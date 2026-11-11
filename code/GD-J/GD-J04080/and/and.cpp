#include<bits/stdc++.h>
#define ll long long
#define lowbit(x) (x&(-x))
using namespace std;
const int N=1e6+5,mod=1e9+7;
inline ll read(){
	ll f=1,tot=0;char ch=getchar();
	while(!('0'<=ch&&ch<='9')){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while('0'<=ch&&ch<='9'){
		tot=tot*10+ch-'0';
		ch=getchar();
	}
	return f*tot;
}
inline void write(ll x){
	if(x<0){
		putchar('-');
		write(-x);
	}else if(x<10){
		putchar(x+'0');
	}else{
		write(x/10);
		putchar(x%10+'0');
	}
	return ;
}
int a[N];bool p[N];
void solve(){
	int n=read(),m=read(),sum=0;
	for(int i=1;i<=n;i++)
		a[i]=read();
	for(int i=30;i>=0;i--){
		int cnt=0;
		for(int j=1;j<=n;j++)
			if((a[j]&(1<<i))!=0&&p[j]==0)cnt++;
		if(cnt>=m){
			for(int j=1;j<=n;j++)
				if((a[j]&(1<<i))==0)p[j]=1;
			sum|=(1<<i);
		}
	}
	write(sum);
	return ;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int T=1;
	//T=read();
	while(T--)solve();
	return 0;
} 
