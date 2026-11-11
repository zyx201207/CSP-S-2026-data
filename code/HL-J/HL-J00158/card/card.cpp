#include<bits/stdc++.h>
using namespace std;
int n,k,m;
int a[10005];
int main(){
cin>>n>>m;
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
for(int i=1;i<=n;i++)
{
	cin>>a[i];
}
cout<<m<<" "<<a[1]<<" "<<n;
return 0;
}
