#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int>
using namespace std;
const int N=5e5+5;
int n,m,a[N],cnt[N];
int vis[N];
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+(ch^48);ch=getchar();}
	return x*f;
}
void sub1(){
	a[n+1]=1e18;
	for(int i=2;i<=n+1;i++){
		if(a[i]!=a[i-1])cout<<i-1<<" ";
	}
	exit(0);
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	n=read(),m=read();
	bool flag=1;
	for(int i=1;i<=n;i++){
		a[i]=read();
		if(i>=2&&a[i]<a[i-1])flag=0;
	}
	if(flag){
		sub1();
	}
	for(int i=1;i<=n;i++){
		stack<int>st;
		fill(vis+1,vis+m+1,0);
		for(int j=i;j<=n;j++){
			if(vis[a[j]]>0){
				while(st.top()!=a[j]){
					vis[st.top()]--;
					st.pop();
				}
			}else{
				vis[a[j]]++;
				st.push(a[j]);
			}
		}
		for(int j=1;j<=m;j++){
			if(vis[j]>0){
				cnt[j]++;
//				cout<<"check: "<<i<<" "<<j<<"\n"; 
			}
		}
	}
	for(int i=1;i<=m;i++)cout<<cnt[i]<<" ";
	return 0;
}
/*
4 3
1 2 1 3

10 3
3 1 2 1 3 2 3 1 2 1

*/
