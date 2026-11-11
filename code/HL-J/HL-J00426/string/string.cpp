#include<bits/stdc++.h>
using namespace std;
long long b,c,d,dcx,n;
string a;
char q,w,e,r,t,y;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(long long i=1;i<=n;i++)
    {
    	cin>>b;
		cin>>q;
    	for(long long j=1;j<=b;j++)
    	{
    		a+=q;
		}
	}
	n=a.size();
	for(long long i=0,j=n-1;i<=(n-1)/2,j>(n-1)/2;i++,j--)
	{
		if(a[j]!=a[i])
		{
			dcx++;
		}
	}
	cout<<dcx;
    return 0;
}

