#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen(and.in,"r",stdin);
    freopen(and.out,"w",stdout);
    long long a,b;
    cin>>a>>b;
    long long m[a];
    long long m1[a];
    for(int i=0;i<a;i++)
    {
    	cin>>m[i];
	}
    sort(m,m+a);
   cout<<m[a-1]&m[a-2];

    return 0;
}
