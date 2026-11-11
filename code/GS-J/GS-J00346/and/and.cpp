#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
long long n,ys,a[200005],q[200005],js=0;cin>>n;
for(int i=0;i<n;i++)
{cin>>q[i];ys=q[i];
while(ys!=0)
{
	a[js]=ys%2;
	js++;ys/=2;
}
cout<<a[i];
}
}
