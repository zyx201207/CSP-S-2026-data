#include<bits/stdc++.h>
using namespace std;
int n;
long long len;
const int N=2e5+10;
struct st{
	int a;
	char c;
};
st s[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int a;
		char c;
		cin>>a>>c;
		len+=a;
		s[i].a=a;
		s[i].c=c;
	}
	len/=2;
	for(int i=1;i<=n;i++)
	{
		int ind=n-i+1;
		if(i>=ind)
		{
			break;
		}
		if(s[i].c==s[ind].c)
		{
			if(s[i].a>=s[ind].a)
			{
				len-=s[ind].a;
				s[i].a-=s[ind].a;
			}
			else
			{
				len-=s[i].a;
				s[ind].a-=s[i].a;
			}
		}
	}
	cout<<len;
	return 0;
}
