#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1,cmp);
	cout<<a[m];
	return 0;
}
