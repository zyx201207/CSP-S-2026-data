#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[200001];
char c[200001];
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,len=0;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
        len+=a[i];
    }
    int m=len/2;
    int cnt=0;
    int jhl1=0,jhl2=n+1;
    int cnt1=0,cur1=0,cnt2=0,cur2=0,ans=0;
    char c1,c2;
    while(jhl1!=n||jhl2!=1||cur1!=0||cur2!=0)
    {
        cnt++;
        //cout<<cnt<<"\n";
        if(cur1==0&&jhl1<n)
        {
            jhl1++;
            cur1=a[jhl1];
            cnt1+=a[jhl1];
            c1=c[jhl1];
        }
        if(cur2==0&&jhl2>1)
        {
            jhl2--;
            cur2=a[jhl2];
            cnt2+=a[jhl2];
            c2=c[jhl2];
        }
        //cout<<jhl1<<' '<<cnt1<<" "<<cur1<<" "<<
        if(cur1>=cur2)
        {
            //cout<<jhl1<<' '<<jhl2<<' '<<c1<<' '<<c2<<"!\n";
            ans+=min(cur1,cur2)*(int)(c[jhl1]!=c[jhl2]);
            cur1-=min(cur1,cur2);
            cur2=0;
        }
        else
        {
            //cout<<jhl1<<' '<<jhl2<<' '<<c1<<' '<<c2<<"!\n";
            ans+=min(cur2,cur1)*(int)(c[jhl2]!=c[jhl1]);
            cur2-=min(cur2,cur1);
            cur1=0;
        }
    }
    cout<<ans/2;
    return 0;
}

