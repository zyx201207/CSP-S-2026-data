#include <bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
	return x>y;
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[10001]={0},b[10001]={0};
	cin>>n>>m; 
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n,cmp);
	for(int i=0;i<m;i++)
		b[i]=a[i];
	sort(b,b+m);
	cout<<b[0];
	return 0;
}
