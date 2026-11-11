#include,bist/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
     long long char c[100000005];
     long long int shu[1000000005];
     int n;
     for(int i=1;i<=n;i++)
     {
         cin>>shu[i]>>c[i];
     }
     for(int i=1;i<=n;i++)
     {
         if(c[i]==c[i-1]) int sum++;
     }
     if(sum==n-1) cout<<"0"<<endl;
     return 0;
}
