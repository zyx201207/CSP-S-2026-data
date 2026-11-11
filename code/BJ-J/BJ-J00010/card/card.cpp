#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=2e5+5;
int n,m,a[N],ans[M];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        string s;
        for(int j=i;j<=n;j++)
        {
            for(int k=0;k<s.size();k++)
            {
                if(int(s[k]-'0')==a[j])
                {
                    string t=s.substr(0,k);
                    s=t;
                    break;
                }
            }
            s+=char(a[j]+'0');
        }
        for(int i=0;i<s.size();i++) ans[int(s[i]-'0')]++;
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
    return 0;
}