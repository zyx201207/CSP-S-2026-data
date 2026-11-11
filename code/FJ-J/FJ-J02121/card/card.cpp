#include <bits/stdc++.h>
using namespace std;
int n,a[100000],s,d;
int main()
{
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
cin>>n>>s>>d;
for(int i=1;i<=n;i++)
{
	cin>>a[i];
}
cout<<a[s]<<" "<<a[d]<<" "<<a[1];
return 0;
}
