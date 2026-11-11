#include<bits/stdc++.h>
using namespace std;
#define int long long
#define uint unsigned long long
#define pii pair<int,int>
inline int read(){
	int f=1,g=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		g=(g<<3)+(g<<1)+(c-'0');
		c=getchar();
	}
	return f*g;
}
inline void write(int x){
	if(x<0)x=-x,putchar('-');
	if(x>9)write(x/10);
	putchar((x%10)+'0');
	return ;
}
const int N=5e5+10;
int n,m,a[N],cnt[N];
bool f[N];
stack<int>st;
bool chkA(){
	for(int i=2;i<=n;i++)if(a[i]<a[i-1])return false;
	return true;
}
void solve1(){
	for(int i=n;i>=1;i--){
		if(a[i]!=a[i+1])cnt[a[i]]+=i;
	}
	for(int i=1;i<=m;i++)write(cnt[i]),putchar(' ');
	return ;
}
void solve2(){
	if(m==1){
		write(n);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(a[i]==a[n])cnt[a[i]]++;
		else cnt[a[i]]++,cnt[a[n]]++;	
	}
	write(cnt[1]),putchar(' '),write(cnt[2]);
	return ;
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	if(chkA()){
		solve1();
		return 0;
	}
	if(m<=2){
		solve2();
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)f[j]=0;
		while(!st.empty())st.pop();
		for(int j=i;j<=n;j++){
			if(!f[a[j]]){
				f[a[j]]=1;
				st.push(a[j]);
			}
			else{
				while(!st.empty()&&st.top()!=a[j]){
					f[st.top()]=0;
					st.pop();
				}
			}
		}
		for(int j=1;j<=m;j++)cnt[j]+=f[j];
	}
	for(int i=1;i<=m;i++)write(cnt[i]),putchar(' ');
	return 0;
}
/*
4 3
1 2 1 3

10 3
3 1 2 1 3 2 3 1 2 1

*/
