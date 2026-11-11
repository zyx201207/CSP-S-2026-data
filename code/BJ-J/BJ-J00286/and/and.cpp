#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main()
{
    freopen("and.in","r","stdin");
    freopen("and.out","w","stdout");
    int n,m,maxx=0,maxn=0;
    cin>>n>>m;
    for(int i = 1;i <= n;i++)
    {
        cin>>a[i];
        maxx=max(maxx,a[i]);
    }
    if(m==1)
    {
        cout<<maxx;
    }
    else
    {
        for(int i = 1;i <= n;i++)
        {
            for(int j = i+1;j <= n;j++)
            {
                int ans=a[i]&a[j];
                maxn=max(maxn,ans);
            }
        }
        cout<<maxn;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
