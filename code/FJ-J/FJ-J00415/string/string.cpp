#include <bits/stdc++.h>
using namespace std;

struct str
{
	long long num;
	char l;
}s[200005];

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>s[i].num >> s[i].l;
	long long i1=1,j1=n,i2=1,j2=s[n].num;
	int ans=0;
	while((i1==j1 && i2<j2) || i1 < j1)
	{
		int min_ij = min(s[i1].num-i2+1 , s[j2].num);
		if(s[i1].l != s[j1].l) ans += min_ij;
		if(i1 < j1)
		{
			if(min_ij == s[j2].num)
			{
				j2 = s[j1-1].num;
				j1--;
			}
			else
			{
				j2 +=min_ij;
		    }
			if(min_ij == s[i1].num - i2 +1)
			{
				i2 = 1;
				i1 ++;
			}
			else
			{
				i2 +=min_ij;
		    }
		}
		else
		{
			break;
		}
	}
	cout<<ans;
	return 0;
}
