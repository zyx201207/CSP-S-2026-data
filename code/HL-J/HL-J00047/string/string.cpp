#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen(string.in,"r",stdin);
    freopen(string.out,"w",stdout);
    int a;
    cin>>a;
    string r;
    int sum=0;
    while(a)
    {
    	int n;
    	char m;
    	cin>>n>>m;
    	sum+=n;
    for(int i=0;i<n;i++)
    {
    	r+=m;
	}
    	a--;
	}
    string r1;
    for(int i=sum-1;i>=0;i--)
    {
    	r1+=r[i];
	}
	bool k=1;
	for(int i=0;i<sum;i++)
	{
		if(r1[i]!=r[i])
		{
			k=0;
		}
	}
	if(k) cout<<0;
	else cout<<1;
    return 0;
}