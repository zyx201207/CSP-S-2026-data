#include <bits/stdc++.h>
#define st first
#define nd second
using namespace std;
typedef pair<long long,char> pic;
pic a[200005];//数组 
bool b[200005];//是否遍历过 
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i].st>>a[i].nd;
	long long ans=0,l=0,r=0;
	for(int i=1,j=n;i<=j;)
	{
		if(!b[i])
			l+=a[i].st,b[i]=1;
		if(!b[j])
			r+=a[j].st,b[j]=1;
		if(a[i].nd!=a[j].nd)
			ans+=min(l,r);
		if(l>r)
			l-=r,r=0;
		else if(r>l)
			r-=l,l=0;
		else
			l=r=0;
		if(a[i].nd==a[i+1].nd||!l)
			i++;
		if(a[j].nd==a[j-1].nd||!r)
			j--;
	}
	cout<<ans;
	return 0;
}//O(N),AC
