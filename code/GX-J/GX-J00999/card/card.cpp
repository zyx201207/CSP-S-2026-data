#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
int m,n,a[1000010],s[1000010];
int main()
{
	freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>m>>n;
    for(int i=1;i<=m;i++)
    {
      cin>>a[i];
      s[i]=s[i-1]+a[i];
    }
    for(int i=1;i<=m;i++)
    {
	    cout<<s[i]<<endl;
	}
    return 0;
}
