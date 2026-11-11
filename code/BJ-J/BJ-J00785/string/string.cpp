#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,cnt,len,ans,p=0,a[200010],pos[200010];
char c[200010];
int getp(int x){
    int l=1,r=cnt,ans;
    while(l<=r){
        int mid=(l+r)/2;
        if(pos[mid]>=x){
            ans=mid;
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    return ans;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        char y;
        cin>>x>>y;
        if(y!=c[cnt]){
            cnt++;
            a[cnt]=x;
            c[cnt]=y;
            pos[cnt]=pos[cnt-1]+x;
        }else{
            a[cnt]+=x;
            pos[cnt]+=x;
        }
        len+=x;
    }
    int i=1;
    /*cout<<len<<"\n";
    for(int i=1;i<=cnt;i++){
        cout<<pos[i]<<" ";
    }
    cout<<"\n";*/
    while(pos[i]<=len/2){
        int l=len-pos[i]+1,r=len-pos[i-1];
        int pl=getp(l),pr=getp(r);
        //cout<<l<<" "<<r<<"\n"<<pl<<" "<<pr<<"\n";
        if(pl==pr&&pos[pl-1]<=l&&l<=pos[pl]&&pos[pl-1]<=r&&r<=pos[pl]){
            if(c[pl]!=c[i]){
                ans+=r-l+1;
            }
            i++;
            continue;
        }
        if(c[pl]!=c[i]){
            ans+=pos[pl]-l+1;
        }
        if(c[pr]!=c[i]){
            ans+=r-pos[pr-1];
        }
        int j=pl+1;
        while(pos[j]<=pos[pr-1]){
            if(c[j]!=c[i]){
                ans+=a[j];
            }
            j++;
        }
        i++;
    }
    cout<<ans;
    return 0;
}
