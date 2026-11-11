#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],sum[200005],maxn,q;
void dg(int p,int x,int s){
	if(p==0){
		for(int i=1;i<=n-m+1;i++){
			dg(i,1,a[i]);
		}
	}
	else{
		if(x==m){
			maxn=max(maxn,s);
			return;
		}
		for(int i=p+1;i<=n-m+x+1;i++){
			dg(i,x+1,s&a[i]);
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	cin>>a[1];
	q=a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
		q&=a[i];
	}
	if(n==m){
		cout<<q;
		exit(0);
	}
	sort(a+1,a+n+1);
	dg(0,0,0);
	cout<<maxn;
}

