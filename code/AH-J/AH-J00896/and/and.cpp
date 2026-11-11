#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200009],c,mx,i;
bool book[200009];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)cin>>a[i];
	for(i=n;i>m;i--)book[i]=1;
	c=a[n];
	do{
		for(i=1;i<=n-1;i++)if(book[i]==1)c=c&a[i];
		mx=max(mx,c);
	}while(next_permutation(book+1,book+1+n));
	cout<<mx;
	return 0;
}
