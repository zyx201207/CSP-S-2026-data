#include <bits/stdc++.h>
using namespace std;
struct v{
	int sz;
}a[100000];
bool cmp(const v &x,const v &y){
	return x.sz>y.sz;
}
long long m,n;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=m;i++){
	     cin>>a[i].sz;
	}
	sort(a+1,a+m+1,cmp);
	cout<<a[n].sz;
	return 0;
}
