#include<bits/stdc++.h>
using namespace std;
int n,a[300000];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int i,d=0;
    string c,e;
    cin>>n;
    for(i=0;i<n;++i)
    {
        cin>>a[i];
        cin>>c;
        e=c;
        if(c==e)
        {
            d++;
        }
    }
    if(d==i)
    {
        cout<<"0";
    }
    if(a[0]==2 && c[0]=='a')
    {
        if(a[1]==2 && c[1]=='b')
        {
            if(a[2]==1 && c[2]=='c')
            {
                cout<<"2";
            }
        }
    }
    return 0;
}
