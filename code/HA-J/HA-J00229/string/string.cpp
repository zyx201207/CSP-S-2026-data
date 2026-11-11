#include<bits/stdc++.h>
using namespace std;

const int N=2e5+10;

string s,s1,s2;
int n,a[N];
char c[N];
long long siz,siz1,siz2,ans;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i]>>c[i];
		siz+=a[i];
	}
	
	int l=1,r=n;
	while(siz1<siz/2)
	{
		if(a[l]>a[r])
		{
			if(c[l]!=c[r])ans+=a[r];
			a[l]-=a[r],siz1+=a[r--];
		}
		
		if(a[r]>a[l])
		{
			if(c[l]!=c[r])ans+=a[l];
			a[r]-=a[l],siz1+=a[l++];
		}
		
		if(a[r]==a[l])
		{
			if(c[l]!=c[r])ans+=a[r];
			l++,siz1+=a[r--];
		}
	}
	
	cout<<ans<<'\n';
	
	return 0;
}
