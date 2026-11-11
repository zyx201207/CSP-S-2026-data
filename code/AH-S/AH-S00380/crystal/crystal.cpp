#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=5e5+5;
LL a[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    LL n,m;
    cin>>n>>m;
    for(LL i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(n%2==1){
        LL mid=a[(n+1)/2],ans=0;
        LL l=(n+1)/2-1,r=(n+1)/2+1;
        ans++;
        while(1){
            if(mid-a[l]<a[r]-mid&&l>=1||r>n){
                m-=(mid-a[l]);
                l--;
            }
            else if(mid-a[l]>=a[r]-mid&&r<=n||l<1){
                m-=(a[r]-mid);
                r++;
            }
            if(m<0){
                break;
            }
            ans++;
            if(l==0&&r==n+1){
                break;
            }
        }
        cout<<ans<<endl;
    }
    else{
        LL mid1=(a[n/2]+a[n/2+1])/2,mid2=mid1+1,mm=m;
        LL ans1=0,ans2=0;
        LL l=n/2,r=n/2+1;
        while(1){
            if(mid1-a[l]<a[r]-mid1&&l>=1||r>n){
                m-=(mid1-a[l]);
                l--;
            }
            else if(mid1-a[l]>=a[r]-mid1&&r<=n||l<1){
                m-=(a[r]-mid1);
                r++;
            }
            if(m<0){
                break;
            }
            ans1++;
            if(l==0&&r==n+1){
                break;
            }
        }
        l=n/2;
        r=n/2+1;
        while(1){
            if(mid2-a[l]<a[r]-mid2&&l>=1||r>n){
                mm-=(mid2-a[l]);
                l--;
            }
            else if(mid2-a[l]>=a[r]-mid2&&r<=n||l<1){
                mm-=(a[r]-mid2);
                r++;
            }
            if(mm<0){
                break;
            }
            ans2++;
            if(l==0&&r==n+1){
                break;
            }
        }
        cout<<max(ans1,ans2);
    }
    return 0;
}
