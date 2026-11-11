#include <bits/stdc++.h>
using namespace std;
int a[200005];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	sort(a+1,a+1+n,cmp);
	long long cnt=a[1];
	for(int i=2;i<=m;i++){
		cnt&=a[i];
	} 
	if(cnt)
	cout<<cnt;
	else
	cout<<a[m];
	return 0;
}
