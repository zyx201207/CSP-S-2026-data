#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m;
int a[N];
int b[N];
int c[N];
int ans=0;
int cmp(int a,int b){
	return a>=b;
}
int main() {
//	freopen("and.in","r",stdin);
//	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	c[1]=a[1];
	for(int i=1;i<=n-m;i++){
		for(int j=0;j<m;j++)
		c[i]=c[i]&a[i+j];
//		cout<<c[i]<<" "; 
	}
	for(int i=1;i<=n-m;i++){
		ans=max(c[i],ans);
	}
	cout<<ans;
	return 0;
}

