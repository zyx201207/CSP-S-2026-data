#include<iostream>
using namespace std;
long long n,a[200005],x=1,y,m,s;
char c[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
    }
    y=n;
    while(x<y)
    {
        m=min(a[x],a[y]);
        if(c[x]!=c[y])
        {
            s+=m;
        }
        a[x]-=m;
        a[y]-=m;
        if(!a[x])
        {
            x++;
        }
        if(!a[y])
        {
            y--;
        }
    }
    cout<<s;
    return 0;
}
