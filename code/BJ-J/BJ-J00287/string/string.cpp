#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
struct node{
    int a;
    char ch;
}t[N];
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    int sum=0;
    for(int i=1;i<=n;i++)
    {
        cin>>t[i].a>>t[i].ch;
        sum+=t[i].a;
    }
    int p,q;
    if(sum%2==0)
    {
        p=sum/2;
        q=sum/2+1;
    }
    else
    {

        p=(sum-1)/2;
        q=(sum-1)/2+2;
    }
    //cout<<p<<" "<<q<<endl;
    int l,r;
    int posl,posr;
    sum=0;
    int flag1=0;
    int flag2=0;
    for(int i=1;i<=n;i++)
    {
        sum+=t[i].a;
        if(sum>=p&&flag1==0)
        {
            l=i;
            posl=p-sum+t[i].a;
            flag1=1;
        }
        if(sum>=q&&flag2==0)
        {
            r=i;
            posr=q-sum+t[i].a;
            flag2=1;
        }
    }
    int cnt=0;
    //cout<<posl<<" "<<l<<" "<<posr<<" "<<r<<" "<<cnt<<endl;
    while(l>=1)
    {

        if(posl<t[r].a-posr+1)
        {

            if(t[l].ch!=t[r].ch)
            {

                cnt+=posl;
            }
            posr=posr+posl;
            l--;
            posl=t[l].a;

        }
        else if(posl>t[r].a-posr+1)
        {

            if(t[l].ch!=t[r].ch)
            {

                cnt+=t[r].a-posr+1;
            }
            posl=posl-(t[r].a-posr+1);
            posr=1;
            r++;
        }
        else
        {

            if(t[l].ch!=t[r].ch)
            {

                cnt+=posl;
            }
            l--;
            posl=t[l].a;
            r++;
            posr=1;
        }
       // cout<<posl<<" "<<l<<" "<<posr<<" "<<r<<" "<<cnt<<endl;
    }
    cout<<cnt;
    return 0;
}
