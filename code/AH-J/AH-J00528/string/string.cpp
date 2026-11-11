#include<bits/stdc++.h>
using namespace std;
int n,a[200005],ans,head,tail,r;
char c[200005];
string s;

int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
    }
    head=1,tail=n;
    while(1)
    {
        if(a[head]<=a[tail])
        {
            if(c[head]!=c[tail])
                ans+=a[head];
            a[tail]-=a[head];
            a[head]=0;
        }
        if(a[head]>a[tail])
        {
            if(c[head]!=c[tail])
                ans+=a[tail];
            a[head]-=a[tail];
            a[tail]=0;
        }
        if(a[head]==0)
        {
            head++;
        }
        if(a[tail]==0)
        {
            tail--;
        }
        if(head>=tail)
        {
            break;
        }
    }
    cout<<ans;
}
