#include<bits/stdc++.h>
#define int long long
using namespace std;
char frt_c[200005],bck_c[200005];
int frt_s[200005],bck_s[200005];
int frt_e[200005],bck_e[200005];
int ans=0;
signed main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int i,j;
    int pos=0;
    int len=0;
    for(i=1;i<=n;i++)
    {
        int num;
        char c;
        cin>>num>>c;
        frt_c[i]=c;
        frt_s[i]=pos+1;
        frt_e[i]=pos+num;
        pos+=num;
        len+=num;
    }
    for(i=n;i>=1;i--)
    {
        bck_c[n-i+1]=frt_c[i];
        bck_s[n-i+1]=len-frt_e[i]+1;
        bck_e[n-i+1]=len-frt_s[i]+1;
    }
    int half_front;
    for(i=1;i<=n;i++)
    {
        if(frt_e[i]>=len/2)
        {
            frt_e[i]=len/2;
            half_front=i;
            break;
        }
    }
    int half_back;
    for(i=1;i<=n;i++)
    {
        if(bck_e[i]>=len/2)
        {
            bck_e[i]=len/2;
            half_back=i;
            break;
        }
    }
    for(i=1;i<=half_front;i++)
    {
        int start_pos=lower_bound(bck_e+1,bck_e+half_back+1,frt_s[i])-bck_e;
        int end_pos=upper_bound(bck_s+1,bck_s+half_back+1,frt_e[i])-bck_s-1;
        for(j=start_pos;j<=end_pos;j++)
        {
            int s1=frt_s[i],e1=frt_e[i],s2=bck_s[j],e2=bck_e[j];
            if(s1>s2)
            {
                swap(s2,s1);
            }
            if(e1>e2)
            {
                swap(e2,e1);
            }
            int overlap=e1-s2+1;
            if(frt_c[i]!=bck_c[j])
            {
                ans+=overlap;
            }
        }
    }
    cout<<ans;
    return 0;
}
