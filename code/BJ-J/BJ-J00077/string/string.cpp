#include<bits/stdc++.h>
using namespace std;
long long p[100000006] = {};
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;

    while(n!=0)
    {
        string a,b;
        cin>>a>>b;
        for(int i = 1;i<=a;i++)
        {
            p[i] = b;
        }
        n-=1;
    }
    return 0;
}
