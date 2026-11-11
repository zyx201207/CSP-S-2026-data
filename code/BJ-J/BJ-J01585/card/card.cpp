#include<bits/stdc++.h>
using namespace std;
int a[500000+7];
int hx[500000+7];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    string s=" ";
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        s=" ";
        for(int j=1;j<=n;j++)
        {
            if(j!=i-1)
            {
                bool f=0;
                for(int k=1;k<=s.size();k++)
                {
                    if(s[k]-'0'==a[j])
                    {
                        for(int l=k;l<=s.size();l++)
                        {
                            s[l]='\0';
                        }
                        f=1;
                        break;
                    }
                }
                if(f==0)s+=a[j]+'0';
            }
        }
        for(int i=1;i<=s.size();i++)
        {
            if(s[i]>='0'&&s[1]<='9')
            hx[s[i]-'0']++;
        }
    }
    for(int i=1;i<=m;i++) cout<<hx[i]<<" ";
    return 0;
}
