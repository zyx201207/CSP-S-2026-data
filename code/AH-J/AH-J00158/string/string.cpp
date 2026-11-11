#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int a[200010],x[200010];
char c[200010],cx[200010];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    int sum=0;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        sum+=a[i];
    }
    int p=sum/2,k=sum%2;
    int e=0,d=0;
    for(int i=1;i<=n;i++){
        if(k==1&&e<=p&&e+a[i]==p+k){
            d=-1;
            continue;
        }else if(k==1&&e<=p&&e+a[i]>p+k){
            x[i]=a[i]-1;
            cx[i]=c[i];
            continue;
        }
        if(k==0&&e+a[i]>p&&e<p){
            x[i]=p-e;
            x[i+1]=a[i]-p+e;
            cx[i]=cx[i+1]=c[i];
            d=1;
            continue;
        }
        x[i+d]=a[i];
        cx[i+d]=c[i];
    }
    int re=0,le=0,ans=0;
    for(int l=0,r=n+d+1;l<r-1;l=l){
        if(le>re) re+=x[--r];
        else if(le<re) le+=x[++l];
        else le+=x[++l],re+=x[--r];
        if(cx[l]!=cx[r]){
            ans+=min(re,le);
        }
        int kl=min(re,le);
        re-=kl;
        le-=kl;
    }
    cout<<ans;
    return 0;
}
