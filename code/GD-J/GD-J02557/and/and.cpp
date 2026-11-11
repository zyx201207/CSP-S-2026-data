#include<iostream>
#include<algorithm>
using namespace std;
long long a[1000000],ans;
bool cmp(long long x,long long y){
	return x>y;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n,cmp);
	cout<<a[0]<<endl;
	return 0;
}
