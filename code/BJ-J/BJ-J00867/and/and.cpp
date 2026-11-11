#include<iostream>
#include<algorithm>
using namespace std;
int a[200000];
bool b[200000];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,ans=0;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(i>n-m-1) b[i]=1;
    }
    do
    {
        int s=-1;
        for(int i=0;i<n;i++)
        {
            if(b[i])
            {
                if(s==-1) s=a[i];
                else s&=a[i];
            }
        }
        ans=max(s,ans);
    }while(next_permutation(b,b+n));
    cout<<ans;
    return 0;
}
