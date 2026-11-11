#include<bits/stdc++.h>
using namespace std;
struct strn{
	int a;
	char c;
};
int main()
{
	//freopen("","r",stdin);
	//freopen("","w",stdout);
	int n,h=0,t;
	long long r=0;
	cin>>n;
	t=n-1;
	strn l[n];
	for(int i=0;i<n;i++)
	{
		cin>>l[i].a>>l[i].c;
	}
	while(h<t)
	{
		if(l[h].c==l[t].c)
		{
			if(l[h].a>l[t].a)
			{
				l[h].a-=l[t].a;
				t--;
			}else if(l[h].a<l[t].a)
			{
				l[t].a-=l[h].a;
				h++;
			}else
			{
				h++;
				t--;
			}
		}
		else
		{
			if(l[h].a>l[t].a)
			{
				l[h].a-=l[t].a;
				r+=l[t].a;
				t--;
			}else if(l[h].a<l[t].a)
			{
				l[t].a-=l[h].a;
				r+=l[h].a;
				h++;
			}else
			{
				r+=l[t].a;
				h++;
				t--;
			}
		}
	}
	cout<<r<<endl;
	return 0;
}
