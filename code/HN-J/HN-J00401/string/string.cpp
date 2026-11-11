#include<bits/stdc++.h>
using namespace std;
struct h
{
	int h1;
	char h2;
	int nxt;
};
h hh[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    int n,nxtt = 1,nl = 0;
    scanf("%d",&n);
    for(int i = 1;i <= n;i++)
    {
    	int a;
    	char b;
    	scanf("%d %c",&a,&b);
    	hh[i].h1 = a;
    	hh[i].h2 = b;
    	hh[i].nxt = ++nxtt;
	}
	for(int i = 1; i <= n;i++)
	{
		if(hh[i].h2 == hh[n - i + 1].h2)
		{
			if(hh[i].h1 != hh[n - i + 1].h1)
			{
				int a = min(hh[i].h1,hh[n - i + 1].h1);
				if(a == hh[i].h1)
				{
					int b = hh[n - i + 1].h1 - hh[i].h1;
					hh[nxtt].nxt = hh[n - i].nxt; 
					hh[n - i].nxt = hh[nxtt].nxt;
					hh[n - i].h1 = b;
					hh[n - i].h2 = hh[n - i + 1].h2;
					nl+=b;
					nxtt++;
				}
				else
				{
					int b = hh[n - i].h1 - hh[i].h1 + hh[n - i + 1].h1;
					hh[n - i].h1 -= b;
					hh[n - i + 1].h1 += b;
					nl+=b;
				}
			}
		}
		else
		{
			if(hh[i].h1 != hh[n - i + 1].h1)
			{
				int a = min(hh[i].h1,hh[n - i + 1].h1);
				if(a == hh[i].h1)
				{
					int b = hh[n - i + 1].h1 - hh[i].h1;
					hh[nxtt].nxt = hh[n - i].nxt; 
					hh[n - i].nxt = hh[nxtt].nxt;
					hh[n - i].h1 = b;
					hh[n - i].h2 = hh[n - i + 1].h2;
					nl+=b;
					nxtt++;
				}
			}
		}
	}
	cout<<nl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
