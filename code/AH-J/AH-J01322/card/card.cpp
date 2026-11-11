#include<bits/stdc++.h>
using namespace std;
queue<unsigned long long> p,o;
unsigned long long a[500050],ans,imax;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    unsigned long long n,m;
    cin>>n>>m;
    for(unsigned long long i=1;i<=n;i++)
    {
		cin>>a[i];
	}
	for(unsigned long long i=n;i>=1;i--)
	{
		cout<<i<<" ";
	}
	fclose(stdin);
    return 0;
}
