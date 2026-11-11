#include<bits/stdc++.h>
using namespace std;
#define maxn 200'0005
#define int long long
int n,d,x[maxn],l[maxn],r[maxn],pl[maxn],pr[maxn],sl[maxn],sr[maxn],ans;
signed main(){
    int c,t;
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        int cnt=1;
        for(int i=1;i<=n;i++){
            while(x[i]-x[cnt]>d){
                cnt++;
            }
            l[i]=cnt;
        }
        cnt=n;
        for(int i=n;i;i--){
            while(x[cnt]-x[i]>d){
                cnt--;
            }
            r[i]=cnt;
        }
        int cnt1=1,cnt2=1,cnt3=n,cnt4=n;
        for(int i=1;i<=n;i++){
            while(cnt1!=n+1&&r[cnt1]<i){
                cnt1++;
            }
            while(cnt2!=n+1&&r[cnt2]<=i){
                cnt2++;
            }
            if(r[l[i]]==i){
                pl[i]=pl[l[i]]-1;
            }
            pl[i]+=cnt2-cnt1+1;
            sl[i]=sl[i-1]+pl[i];
        }
        for(int i=n;i;i--){
            while(cnt3&&l[cnt3]>i){
                cnt3--;
            }
            while(cnt4&&l[cnt4]>=i){
                cnt4--;
            }
            if(l[r[i]]==i){
                pr[i]=pr[r[i]]-1;
            }
            pr[i]+=cnt3-cnt4+1;
            sr[i]=sr[i+1]+pr[i];
        }
        cnt1=cnt2=cnt3=cnt4=1;
        for(int i=1;i<n;i++){
            while(cnt1!=n+1&&r[cnt1]<i+1){
                cnt1++;
            }
            while(cnt2!=n+1&&r[cnt2]<=i+1){
                cnt2++;
            }
            while(cnt3!=n+1&&l[cnt3]<i){
                cnt3++;
            }
            while(cnt4!=n+1&&l[cnt4]<=i){
                cnt4++;
            }
            //ans+=(sl[min(cnt2,i)-1]-sl[min(cnt1,i)-1])*(sr[max(cnt3,i+2)]-sr[max(cnt4,i+2)]);

            // ans+=(sl[min(cnt2,i)-1]-sl[min(cnt1,i)-1])*(max(cnt4,i+2)-max(cnt3,i+2));
            // ans+=(min(cnt2,i)-min(cnt1,i))*(sr[max(cnt3,i+2)]-sr[max(cnt4,i+2)]);
            // ans-=(min(cnt2,i)-min(cnt1,i))*(max(cnt4,i+2)-max(cnt3,i+2));
            if(l[i]==l[i+1]&&r[l[i]]==i+1&&l[i]!=i){
                ans+=(pl[l[i]]-1)*(max(cnt4,i+2)-max(cnt3,i+2));
                assert(pl[l[i]]-1>=0);
            }
            if(r[i]==r[i+1]&&l[r[i]]==i&&r[i+1]!=i+1){
                ans+=(min(cnt2,i)-min(cnt1,i))*(pr[r[i]]-1);
                assert((pr[r[i]]-1)>=0);
            }
            ans+=(min(cnt2,i)-min(cnt1,i))*(max(cnt4,i+2)-max(cnt3,i+2));
                assert(min(cnt2,i)-min(cnt1,i)>=0);
                assert((max(cnt4,i+2)-max(cnt3,i+2))>=0);
            if(l[i]==l[i+1]&&r[l[i]]==i+1&&r[i]==r[i+1]&&l[r[i]]==i&&l[i]!=i&&r[i+1]!=i+1){
                ans+=(pl[l[i]]-1)*(pr[r[i]]-1);
            }
        }
        cout<<ans<<'\n';
        for(int i=1;i<=n;i++){
            x[i]=l[i]=r[i]=pl[i]=pr[i]=sl[i]=sr[i]=0;
        }
        ans=0;
    }
    return 0;
}