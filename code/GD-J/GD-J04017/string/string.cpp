#include<bits/stdc++.h>
using namespace std;
struct str{
	long long s;
	char ch;
}a[200005];
long long n,ans,r,l;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i].s>>a[i].ch;
	l=1;
	r=n;
	while(r>=l)
	{
		if(a[l].s>a[r].s)
		{
			a[l].s-=a[r].s;
			if(a[l].ch!=a[r].ch)
			ans+=a[r].s;
			r--;
		}
		else if(a[l].s<a[r].s)
		{
			a[r].s-=a[l].s;
			if(a[l].ch!=a[r].ch)
			ans+=a[l].s;
			l++;
		}
		else if(a[l].s==a[r].s)
		{
			if(a[l].ch!=a[r].ch)
			ans+=a[r].s;
			r--;
			l++;
		}
	}
	cout<<ans;
	return 0;
}



