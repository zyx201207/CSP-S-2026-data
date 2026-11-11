#include<bits/stdc++.h>
using namespace std;
struct node
{
    int num;string ss;
    bool operator < (node b) const{
        return ss<b.ss;
    }
}s[200010];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i].num;
        int x=s[i].num;
        if(x==0)
        {
            i--,n--;continue;
        }
        for(int j=1;j<=30;j++)
        {
            char r=x%2+'0';
            x/=2;
            s[i].ss=r+s[i].ss;
        }
    }
    sort(s+1,s+n+1);
    int ans=s[n].num;
    /*for(int i=1;i<=n;i++)
    {
        cout<<s[i].num<<" "<<s[i].ss<<endl;
    }
    cout<<n<<" "<<k<<endl;*/
    for(int i=n;i>=n-k+1;i--)
    {
        //cout<<s[i].num<<" "<<s[i].ss<<endl;
        ans&=s[i].num;
    }
    cout<<ans;
    return 0;
}
