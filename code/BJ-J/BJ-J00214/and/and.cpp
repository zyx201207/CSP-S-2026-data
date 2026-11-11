#include<bits/stdc++.h>
using namespace std;

int n,m,cnt = 0;
int s[1000000];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i <= n;i++)
        cin >> s[i];
    for(int i = 1;i<=n;i++)
    {
        for(int j = 1;j <=n;j++)
        {
            for(int k = 1;k<=n;k++)
            {
                if(cnt<s[i]&s[j])
                {
                    cnt = s[i]&s[j];
                }
            }
        }
        
    }
    cout<<cnt;
    return 0;
}