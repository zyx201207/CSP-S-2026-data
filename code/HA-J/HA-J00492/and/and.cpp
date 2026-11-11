#include <bits/stdc++.h>
using namespace std;
int main()
{   
    freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	long long n,a;
	int m[300005];
	cin>>n>>a;
    for(int i=1;i<=n;i++)
    {
    	cin>>m[i];
    }
    sort(m+1,m+n+1);
    int b=0;
    for(int i=n;i>0;i--)
    {
    	if(b==a)
    	{
    		cout<<m[i+1];
    	}
		b++;
    	
    }
	return 0;
}
