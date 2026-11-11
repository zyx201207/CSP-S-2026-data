#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int n,a[N],sum[N],b[N];
void solve(){
    cin>>n;int ans=0;
    for(int i=1;i<=n;i++){
        char c;cin>>a[i]>>c;
        b[i]=c-'a'+1;
    }
    // for(int i=1;i<=n;i++)cout<<b[i]<<" ";
    for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
    int cnt1=0,cnt2=0;
    int i=1,j=n;
    while(cnt1+cnt2<sum[n]){
        if(b[i]==b[j]){
            if(a[i]==a[j]){
                cnt1+=a[i],cnt2+=a[j];
                j--;i++;
                continue;
            }
            if(a[i]<a[j]){
                cnt1+=a[i],cnt2+=a[i];
                a[j]-=a[i];i++;
                continue;
            }
            else if(a[i]>a[j]){
                cnt1+=a[j],cnt2+=a[j];
                a[i]-=a[j];j--;
            }
            continue;
        }
        if(cnt1+cnt2==sum[n])break;
        if(b[i]!=b[j]){
            if(a[i]==a[j]){
            cnt1+=a[i];ans+=a[i];cnt2+=a[i];j--;i++;
            continue;
            }
            else if(a[i]<a[j]){
            cnt1+=a[i];cnt2+=a[i];ans+=a[i];a[j]-=a[i];i++;
            continue;
            }
            else if(a[i]>a[j]){
            cnt1+=a[j];cnt2+=a[j];a[i]-=a[j];ans+=a[j];j--;
            }        
        }

    }
    cout<<ans<<"\n";
}
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}