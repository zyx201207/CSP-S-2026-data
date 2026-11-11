#include<bits/stdc++.h>
using namespace std;
struct s
{
    long a;
    char c;
};
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    long long ans=0;
    s cotv[200005];
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>cotv[i].a>>cotv[i].c;
    }
    int l=0,r=n-1;
    while(l<r)
    {
        if(cotv[l].c!=cotv[r].c)
        {
            ans+=min(cotv[l].a,cotv[r].a);
        }
        if(cotv[l].a>cotv[r].a)
        {
            cotv[l].a-=cotv[r].a;
            r--;
        }
        else if(cotv[l].a<cotv[r].a)
        {
            cotv[r].a-=cotv[l].a;
            l++;
        }
        else
        {
            l++;
            r--;
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
