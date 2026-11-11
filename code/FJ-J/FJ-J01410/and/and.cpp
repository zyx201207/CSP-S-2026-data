#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100005],x,o,r;
void dfs(long long aa,int b,int c){
	if(c==m){
		r=max(r,aa);
		return ;
	}if(b==n){
		return ;
	}for(int i=b+1;i<=n;i++){
		dfs((aa&a[i]),i,c+1);
	}
}int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		x=max(x,a[i]);
		if(i==1){
			o=a[i];
		}o&=a[i];
	}if(m==1){
		cout<<x;
		return 0;
	}if(m==n){
		cout<<o;
		return 0;
	}if(n<=2000){
		dfs((long long)(pow(2,30)-1),0,0);
		cout<<r;
		return 0;
	}sort(a+1,a+n+1);
	cout<<a[n-m+1];
	return 0;
}
