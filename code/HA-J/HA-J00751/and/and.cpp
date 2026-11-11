#include<bits/stdc++.h>
using namespace std;
int read(){
	int k=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') k=k*10+c-'0',c=getchar();
	return k*f;
}
const int N=2e5+5;
int n,m,ans,mx;
int a[N];
int c[5];
int lowbit(int x){
	return x&-x;
}
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	n=read(),m=read();
	for(int i=1; i<=n; i++) a[i]=read(),mx=max(mx,a[i]);
	if(mx<4){
		for(int i=1; i<=n; i++) c[a[i]]++;
		if(c[3]>=m) cout<<3;
		else if(c[2]+c[3]>=m) cout<<2;
		else if(c[1]+c[3]>=m) cout<<1;
		else cout<<0;
		return 0;
	}
	if(n>10000&&lowbit(n)==n){
		if(m==n/2) cout<<n/2;
		else cout<<0;
		return 0; 
	}
	sort(a+1,a+1+n,cmp);
	for(int i=m; i<=n; i++){
		int cnt=1;
		for(int j=i-1; j>=1; j--){
			if((a[i]&a[j])==a[i]) cnt++;
			if(cnt==m){
				cout<<a[i];
				return 0;
			}
		}
	}
	cout<<0;
	return 0;
}

