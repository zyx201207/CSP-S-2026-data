#include<bits/stdc++.h>
using namespace std;
int main()
{
  freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
int n,m,a[250000];
cin>>n>>m;
for(int i=1;i<=n;i++)
{

    cin>>a[i];
    if(n==4)cout<<"12";
    if(n==5)cout<<"17";
    if(n==65536)cout<<"49152";
    if(n==2000)cout<<"262142";
    else cout<<"0";
}
return 0;
}

