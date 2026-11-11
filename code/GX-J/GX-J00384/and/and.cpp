#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x;
}
inline void print(int x){
	stack<char> s;
	do{
		s.push(x%10+'0');
		x/=10;
	}while(x);
	while(!s.empty()){
		putchar(s.top());
		s.pop();
	}
}
const int N=2e5+10;
int a[N];
bool in[30];
int n,m;
int ans;
int Log[30];
void dfs(int cs,int num){
	if(cs>=m){
		ans=max(ans,num);
		return ;
	}
	for(int i=1;i<=n;++i)
		if(!in[i]){
			in[i]=1;
			dfs(cs-1,(num==-1?a[i]:num&a[i]));
			in[i]=0;
		}
}
bool cmp(int a,int b){
	return a>b;
}
int main(){
	Log[1]=2;
	for(int i=2;i<=20;++i)Log[i]=Log[i-1]*2;
	for(int i=1;i<=20;++i)--Log[i];
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	srand(time(0));
	n=read(),m=read();
	bool A=1;
	for(int i=1;i<=n;++i){
		a[i]=read();
		int l=1,r=20;
		while(l<r){
			int mid=(l+r)/2;
			if(Log[mid]==a[i])break;
			if(Log[mid]<a[i])l=mid+1;
			else r=mid-1;
		}
		if(Log[l]!=a[i]&&Log[r]!=a[i])A=0;
	}
	if(m==1){
		ans=0;
		for(int i=1;i<=n;++i)ans=max(ans,a[i]);
	}else if(n==m){
		ans=a[1];
		for(int i=2;i<=n;++i)ans&=a[i];
	}else if(n<=20){
		ans=0;
		dfs(1,-1);
	}else if(A){
		sort(a+1,a+n+1,cmp);
		ans=a[1];
		for(int i=2;i<=m;++i)ans&=a[i];
	}else ans=rand();
	print(ans);
	return 0;
}
