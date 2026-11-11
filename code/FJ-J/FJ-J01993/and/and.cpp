#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
bool cmp(int x,int y)
{
	return x>y;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	sort(a+1,a+n+1,cmp);
	cout<<a[m];
	return 0;
}