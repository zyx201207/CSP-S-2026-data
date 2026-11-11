#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N=200005;
LL n;
LL a[N],cnt,ls,rs,L;
string c;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cin>>c[i];
		L+=a[i];
	} 
	LL l=1,r=a[n];
	LL limit=a[1];
	char t1=c[1],t2=c[n-1];
	int j1=1,j2=n;
	while(ls+rs<L)
	{
		if(l>limit) 
		{
			l=1;
			j1++;
			limit=a[j1];
			t1=c[j1];
		}else if(r<=0)
		{
			j2--;
			r=a[j2];
			t2=c[j2];
		}
		if(t1!=t2) cnt++;
		l++;r--;ls++;rs++;

	}
	cout<<cnt;
	return 0;
}
