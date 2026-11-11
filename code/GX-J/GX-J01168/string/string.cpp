#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
int n;
int sum=0;
int cd=0;
cin>>n;
int i=0;
vector<int>sz(n);
vector<char>zm(n);
for (int i=0; i<=n-1;i=i+1)
{
cin>>sz[i]>>zm[i];
cd=cd+sz[i];
}
vector<char>zz(cd);

for (int j=0;j<=n-1;j=j+1)
{
    for (i=0;i<=sz[j];i=i+1)
        {zz[i]=zm[j];
        }
}



return 0;
}
