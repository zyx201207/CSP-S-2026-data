#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[200005];
string s;
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int b=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	b=a[1];
	for(int i=2;i<=m;i++){
		b=b&a[i];
	}
	cout<<b;
	return 0;
}
