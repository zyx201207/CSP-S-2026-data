#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    log long n,a,num=0;
    char b;
    string m;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a>>b;
        for(int i=1;i<=a;i++)
        {
            m+=b;
        }
    }
    for(int i=1;i<=m.size()-1/2;i++)
    {
        if(m[i-1]!=m[m.size()-i]) num++;
    }
    cout<<num;
    return 0;
}
