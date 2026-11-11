#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005];
int ans=1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    long long v=0;
    v=a[2]-a[1];
    for(int l=1,r=2;;)
    {
        if(l>r)break;
        for(;;)
        {
            r++;
            int ram=v;
            if(r>n)
            {
                r--;
                break;
            }
            if(r<=n&&v<=m)
                v=v+(a[r]-a[r-1])*(r-l);
            if(v>m)
            {
                v=ram;r--;
                break;
            }
        }
        //cout<<v<<" "<<l<<" "<<r<<" "<<r-l+1<<" "<<ans<<endl;
        if(v<=m)
            ans=max(ans,r-l+1);
        l++;
        v=v-(a[r]-a[l-1]);
    }
    cout<<ans;
    return 0;
}
