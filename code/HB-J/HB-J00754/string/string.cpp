#include<bits/stdc++.h>
#define int long long
using namespace std;
struct st{
    int b,e;
    char c;
};
vector<st> v;
signed main()
{
    //freopen("string.in","r",stdin);
    //freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    int sum=0;
    for(int i=1;i<=n;i++){
        int x;
        char c;
        cin>>x>>c;
        v.push_back({sum,sum+x-1,c});
        sum+=x;
    }
    int ans=0;
    if(sum%2==1){
        int mid=sum/2;
        int x,xl,xr;
        int l=0,r=n-1;
        while(l<=r){
            int m=(l+r)/2;
            if(v[m].b<=mid&&v[m].e>=mid){
                x=m;
                break;
            }
            else if(v[m].b>mid){
                r=m-1;
            }
            else{
                l=m+1;
            }
        }
        l=mid-min(mid-v[x].b,v[x].e-mid),r=mid+min(mid-v[x].b,v[x].e-mid);
        xl=x,xr=x;
        while(l>0&&r<sum-1){
            if(l==v[xl].b){
                xl--;
            }
            if(r==v[xr].e){
                xr++;
            }
            int k=min(l-v[xl].b,v[xr].e-r);
            if(v[xl].c!=v[xr].c){
                ans+=k;
            }
            l-=k;
            r+=k;
        }
        /*
        */
    }
    else{
        int mid=sum/2;
        int x,xl,xr;
        int l=0,r=n-1;
        while(l<=r){
            int m=(l+r)/2;
            if(v[m].b<=mid&&v[m].e>=mid){
                x=m;
                break;
            }
            else if(v[m].b>mid){
                r=m-1;
            }
            else{
                l=m+1;
            }
        }
        l=mid-min(mid-v[x].b,v[x].e-mid),r=mid+min(mid-v[x].b,v[x].e-mid)-1;
        xl=x,xr=x;
        while(l>0&&r<sum-1){
            if(l==v[xl].b){
                xl--;
            }
            if(r==v[xr].e){
                xr++;
            }
            int k=min(l-v[xl].b,v[xr].e-r);
            if(v[xl].c!=v[xr].c){
                ans+=k;
            }
            l-=k;
            r+=k;
        }
        /*
        */
    }
    cout<<ans;
    return 0;
}
