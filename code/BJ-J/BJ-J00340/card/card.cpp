#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],t[3];
bool flag=1;
string s;

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(i>1&&a[i]<a[i-1])
            flag=0;
    }
    if(flag)
    {
        for(int i=1;i<n;i++)
            if(a[i]<a[i+1])
                cout<<i<<' ';
        cout<<n;
        return 0;
    }
    if(m<3)
    {
        for(int x=1;x<=n;x++)
        {
            s="";
            for(int i=x;i<=n;i++)
            {
                if(s==""&&a[i]==2)
                    s+='2';
                else if(s==""&&a[i]==1)
                    s+='1';
                else if(s=="2"&&a[i]==1)
                    s+='1';
                else if(s=="1"&&a[i]==2)
                    s+='2';
                else if(s=="12"&&a[i]==1)
                    s="1";
                else if(s=="21"&&a[i]==2)
                    s="2";
            }
            for(int i=0;i<s.length();i++)
                t[(s[i]-'0')]++;
        }
        cout<<t[1]<<' '<<t[2];
        return 0;
    }
    return 0;
}
