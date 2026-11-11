#include<bits/stdc++.h>
using namespace std;
long long s[200005];
bool cmp(int x,int y)
{
	return x>y;
}
int main() 
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m;
	cin>>n>>m;
	long long a[200005]; 
	cin>>a[1];
	for(int i=2;i<=n;++i)
    {
    	cin>>a[i];
	} 
	sort(a+1,a+n+1,cmp);
	s[1]=a[1];
	for(int i=2;i<=n;++i)
    {
    	s[i]=(s[i-1]&a[i]);
	} 
	long long maxn=-1;
	for(int i=m;i<=n;++i)
    {
    	maxn=max(s[i],maxn);
	} 
	cout<<maxn<<endl;
	return 0;
}
