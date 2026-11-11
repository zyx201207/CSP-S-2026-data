#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long cnt;
struct sp
{
	char w;
	int num;	
};

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	int n,l,r;
	int mid;
	sp s[N];
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i].num;
		cin>>s[i].w;
	}
	l=1;r=n;mid=n/2;
	
	while(l<=mid && r>mid+n%2)
	{
		if(s[l].num>=s[r].num)
		{
			if(s[l].w!=s[r].w) cnt+=s[r].num;
			s[l].num-=s[r].num;
			r--;
		}
		else
		{
			if(s[l].w!=s[r].w) cnt+=s[l].num;
			s[r].num-=s[l].num;
			l++;
		}
    }
	cout<<cnt;
	return 0;
}