#include<bits/stdc++.h>
using namespace std;
const int N=1100000;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
string a,b;
int d,c[N]={},m=0,k=0;
cin>>d;
for(int i=0;i<d;i++)
{
cin>>c[i];
cin>>b[i];
for(int j=0;j<c[i];j++)
{
a+=b[i];
m++;
}
}
m=m-1;
for(int i=0;i<m/2;i++)
{if(a[i]!=a[m-i])

{
k++;
}
}
cout<<k;
return 0;
}
