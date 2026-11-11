#include <bits/stdc++.h>
using namespace std;
string a;
char d;
long long s,n;
long long f=0;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>s>>d;

        while(s>0)
        {
            a+=d;
            s--;
        }
    }
    for(int i=0;i<a.size();i++)
    {
        if(a[i]!=a[a.size()-1-i])
        {
            a[a.size()-1-i]=a[i];
            f++;
        }
    }
    cout <<f;
    return 0;
}
