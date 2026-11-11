#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
struct sub{
	int a;
	char ch;
}s[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>s[i].a>>s[i].ch;
	int l=1,r=n;
	long long ans=0;
	while(l<r)
	{
		int la=s[l].a,ra=s[r].a;
		char lch=s[l].ch,rch=s[r].ch;
		if(lch==rch)
		{
			if(la==ra)
				l++,r--;
			else if(la<ra)
				s[r].a-=la,l++;
			else s[l].a-=ra,r--;
			continue;
		}
		if(la==ra)
			ans+=la,l++,r--;
		else if(la<ra)
			ans+=la,s[r].a-=la,l++;
		else ans+=ra,s[l].a-=ra,r--;
	}
	cout<<ans;
	return 0;
} 
