
#include<bits/stdc++.h>
using namespace std;
int a[200005];
char b[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int y;
        cin>>y;
        char t;
        cin>>t;
        a[i]=y;
        b[i]=t;
    }
    long long cnt=0;
    int left=1,right=n;
    for(int j=1;j<=n;j++)
    {
        if(b[left]==b[right])
        {
            int k=min(a[left],a[right]);
            a[left]-=k;
            a[right]-=k;
            if(a[left]==0)
            {
                left+=1;
            }
            if(a[right]==0)
            {
                right-=1;
            }
        }
        else
        {
            int k2=min(a[left],a[right]);
            a[left]-=k2;
            a[right]-=k2;
            cnt+=k2;
            if(a[left]==0)
            {
                left+=1;
            }
            if(a[right]==0)
            {
                right-=1;
            }
        }
    }
    cout<<cnt;
    return 0;
}
