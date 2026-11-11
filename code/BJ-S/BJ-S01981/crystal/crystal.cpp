#include <bits/stdc++.h>
#define test 1
using namespace std;
int n,m,ans=0;
long long crys[500050],qzad[500050];
bool check(int st,int pos)
{
    long long sum=qzad[st]-qzad[pos-1],act=crys[st]*(st-pos+1);
    if(act-sum>m)return 0;
    else return 1;
}
int main()
{
    #ifdef test
     freopen("crystal.in","r",stdin);
     freopen("crystal.out","w",stdout);
    #endif // test
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>crys[i];
    sort(crys+1,crys+1+n);
    for(int i=1;i<=n;i++)
        qzad[i]=qzad[i-1]+crys[i];
    for(int i=1;i<=n;i++)
    {
        int lef=1,rig=i,mid=(lef+rig)/2;
        while(lef<rig)
        {
            if(check(i,mid))
                rig=mid;
            else
                lef=mid+1;
            mid=(lef+rig)/2;
        }
        ans=max(ans,i-mid+1);
    }
    cout<<ans;
    return 0;
}
//315275