#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],drc,drct,ans,cnt=1e18,num;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    drc=a[1];
    drct=1;
    for(long long i=2;i<=n-1;i++){
        if(a[i+1]-a[i-1]<cnt){
            cnt=a[i+1]-a[i-1];
            drc=a[i];
            drct=i;
            num=(a[i+1]-a[i-1]+1)/2;
        }
    }
    for(long long i=drct;i<=n-1;i++){
        if(a[i+1]-a[i]<=num){
            drc=a[i+1];
            drct=i+1;
        }
        else{
            break;
        }
    }
    long long tim=0;
    for(int i=1;i<=n;i++){
        if(a[i]==drc){
            if(tim==0) drct=i;
            tim++;
        }
    }
    ans=tim;
    long long l=drct,r=drct+tim-1;
    while((l>=1||r<=n)&&m){
        if(a[l]==drc&&l>1){
            l--;
            continue;
        }
        if(a[r]==drc&&r<n){
            r++;
            continue;
        }
        if(drc-a[l]>a[r]-drc&&a[r]-drc!=0&&r<=n){
            if(a[r]-drc<=m){
                m-=a[r]-drc;
                ans++;
                r++;
            }
            else{
                break;
            }
        }
        else if(drc-a[l]==a[r]-drc&&drc-a[l]!=0&&r<=n){
            if(a[r]-drc<=m){
                m-=a[r]-drc;
                ans++;
                r++;
            }
            else{
                break;
            }
        }
        else if(drc-a[l]<a[r]-drc&&drc-a[l]!=0&&l>=1){
            if(drc-a[l]<=m){
                m-=drc-a[l];
                ans++;
                l--;
            }
            else break;
        }
        else if(drc-a[l]==0&&a[r]-drc!=0&&a[r]-drc<=m&&r<=n){
            m-=a[r]-drc;
            ans++;
            r++;
        }
        else if(a[r]-drc==0&&drc-a[l]!=0&&drc-a[l]<=m&&l>=1){
            m-=drc-a[l];
            ans++;
            l--;
        }
        else if(drc-a[l]>a[r]-drc&&a[r]-drc==0&&l>=1){
            if(drc-a[l]<=m){
                m-=drc-a[l];
                ans++;
                l--;
            }
            else break;
        }
        else if(drc-a[l]<a[r]-drc&&drc-a[l]==0&&r<=n){
            if(a[r]-drc<=m){
                m-=a[r]-drc;
                ans++;
                r++;
            }
            else{
                break;
            }
        }
        else break;
    }
    cout<<ans;
    return 0;
}
