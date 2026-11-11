#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n, m;
    string s;
    long long h[300010];
    cin>>n>>m;
    for(int i=0; i<n; i++)
    {
        cin>>s[i];
    }
    for(int g=0; g<n; g++)
    {
        int d[300100];
        for(int i=0; i<300010; i++)
        {
            d[i]=0;
        }
        for(int i=g; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(d[j]==s[i])
                {
                    for(int f=j; f<300010; f++)
                    {
                        d[f]=0;
                    }
                }
            }
            d[i]=s[i];cout<<s[i]<<' ';
        }
        for(int i=0; i<n; i++)
        {
            cout<<d[i]<<' ';
        }
        cout<<'\n';
        for(int i=0; i<n; i++)
        {
            if(d[i]!=0)
            {
                h[i]++;
            }
        }
    }
    for(int i=0;i<m;i++){
        cout<<h[i]<<' ';
    }
    return 0;
}
