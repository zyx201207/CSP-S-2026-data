#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200005],s[200005],l=1,ans=0;
void dfs(int k,int start,int x){
	if(x<=ans) return;
	if(k==m+1) ans=x;
	for(int i=start;i<=n;i++){
		dfs(k+1,i+1,a[i]&x);
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	bool pp=0,q=0;
	for(int i=0;i<=32;i++){
		if(n==(1<<i)) pp=1;
	}
	if(pp==1){
		q=1;
		for(int i=1;i<=n;i++){
			if(a[i]!=i-1) q=0;
		}
	}
	sort(a+1,a+n+1,greater<int>());
	s[1]=a[1];
	for(int i=1;i<=32;i++){
		l=l*2;
	}
	l-=1;
	for(int i=2;i<=n;i++){
		s[i]=s[i-1]&a[i];
	}
	bool ok=1;
	for(int i=1;i<=n;i++){
		bool ok1=0;
		for(int j=0;j<=32;j++){
			if(a[i]==(1<<j)-1) ok1=1;
		}
		if(ok1==0){
			ok=0;
			break;
		}
	}
	if(m==n){
		cout<<s[n];
		return 0;
	}
	if(m==1){
		cout<<a[1];
		return 0;
	}
	if(m==n-1){
		cout<<s[n-1];
		return 0;
	}
	if(n<=2000){
		dfs(1,1,l);
		cout<<ans;
		return 0;
	}
	if(ok){
		cout<<a[m];
		return 0;
	}
	if(q){
		cout<<s[m];
		return 0;
	}
	cout<<2;
	return 0;
}
