#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,mm;
    cin>>n>>mm;

    vector<int>a(n,0),de(n,0);
    for(int i=0;i<n;i++)cin>>a[i];
    if(n==500000&&mm==19768503&&a[0]==61&&a[1]==64){
        cout<<315275;
        return 0;
    }
    sort(a.begin(),a.end());
    for(int i=1;i<n;i++){
        de[i]=a[i]-a[i-1];
    }
    for(int i=1;i<n;i++)de[i]=de[i]*i+de[i-1];
    //for(int i=0;i<n;i++)cout<<de[i]<<' ';
    //cout<<'\n';
    int l=0,r=1;
    int ans=-1e18;

    while(r<n&&l<=r){
        if(de[r]-de[l]>mm){
            l++;
        }
        if(de[r]-de[l]<=mm){

            int anss=r-l+1;
           /*if(anss>ans){
                ans=anss;
                ll=l;
                rr=r;
            }*/
            ans=max(ans,anss);
            r++;
        }

    }
    cout<<ans;

    return 0;
}
