#include<bits/stdc++.h>
using namespace std;
string s;
long long a[2000005],ans,cnt[2000005];
char b[20000005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;

    for(int i=1;i<=n;i++)
    {
         cin>>a[i]>>b[i];
         cnt[i]=a[i];
    }
    for(int l=1,r=n;l<=n;)
    {
       while(cnt[l]>0&&cnt[r]>0)
       {
           if(b[l]!=b[r])
           {
               ans++;
               //cout<<b[l]<<" "<<l<<" "<<b[r]<<" "<<r<<endl;
           }
            cnt[l]--,cnt[r]--;
       }
       if(cnt[l]==0) l++;
       else if(cnt[r]==0) r--;
       else l++,r--;
    }
    cout<<ans;
    return 0;
}
/*
3
2 a
2 b
1 c
*/
