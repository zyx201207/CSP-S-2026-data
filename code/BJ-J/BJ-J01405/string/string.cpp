#include <bits/stdc++.h>
using namespace std;
struct zu
{
    long long a;
    char c;
}hui[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i = 1;i<=n;i++)
    {
        cin>>hui[i].a>>hui[i].c;
    }
    long long sum=0;
    int l = 1,r = n;
    while(l < r)
    {
        if(hui[l].c==hui[r].c)
        {
            int minn = min(hui[l].a,hui[r].a);
            hui[l].a-=minn;
            hui[r].a-=minn;
            if(hui[l].a==0) l++;
            if(hui[r].a==0) r--;
        }
        else
        {
            int minn = min(hui[l].a,hui[r].a);;
            hui[l].a-=minn;
            hui[r].a-=minn;
            sum+=minn;
            if(hui[l].a==0) l++;
            if(hui[r].a==0) r--;
        }
    }
    cout<<sum;
    return 0;
}
