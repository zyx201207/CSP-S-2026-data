#include<iostream>
#include<vector>
#define ll long long
#define x first
#define y second
using namespace std;

const ll N=2e6+10;
ll n,a[N],ans;
pair<ll,ll> l,r;
char c[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i)
		cin>>a[i]>>c[i];
	
	//Ë«Ö¸ÕëÎ¬»¤
	l.x=1,l.y=a[1],r.x=n,r.y=a[n];
	while(l<=r)
	{
		if(c[l.x]!=c[r.x])
			ans+=min(l.y,r.y);
		if(l.y>r.y)
		{
			l.y-=r.y;
			--r.x;
			r.y=a[r.x];
		}
		else if(l.y<r.y)
		{
			r.y-=l.y;
			++l.x;
			l.y=a[l.x];
		}
		else
		{
			++l.x;
			l.y=a[l.x];
			--r.x;
			r.y=a[r.x];
		}

	}
	
	cout<<ans;

	fclose(stdin);
	fclose(stdout);	
	return 0;
}
