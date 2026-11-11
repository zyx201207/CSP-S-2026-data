#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n,m;
int a[N];
int mxi=0;
int mx;
bool cmp(int x,int y){
	return (mx&x)>(mx&y);
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[mxi]<a[i]) mxi=i;
	}
	if(n==m){
	   int sum=a[1];
	   for(int i=2;i<=n;i++) sum&=a[i];
	   cout<<sum;
	   return 0;
	}
	mx=a[mxi];
	a[mxi]=0;
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=m-1;i++) mx=(mx&a[i]);
	cout<<mx;
	return 0;
} 
