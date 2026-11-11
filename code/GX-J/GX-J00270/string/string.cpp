#include<bits/stdc++.h>
using namespace std;
char x;
int n,cnt=0;;
string ch;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        ch[i]=x;
    }
    int l=1,cnt1=0,cnt2=cnt/2;
    if(cnt%2==0)
    {
        for(int i=1;i<=cnt2;i++)
        {
            for(int j=cnt2;j<=n;j++)
            {
                if(ch[i]!=ch[j])
                {
                    cnt1++;
                }
            }
        }
        cout<<cnt1;
    }
    else
    {
        for(int i=1;i<=cnt2;i++)
        {
            for(int j=cnt2;j<=n;j++)
            {
                if(ch[i]!=ch[j])
                {
                    cnt1++;
                }
            }
        }
        cout<<cnt1;
    }
    return 0;
}
