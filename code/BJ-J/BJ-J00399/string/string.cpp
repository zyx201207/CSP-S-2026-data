#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200010],b[200010];
char c[200010];
int main(){
    ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ll n,ans=0,mid,cnt,cnt2,cnt3,cnt4,sum;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
    cnt=1,cnt2=a[1],cnt3=n,cnt4=a[n];
    while(cnt<=cnt3){
        if(cnt2<=cnt4&&c[cnt]!=c[cnt3])ans+=cnt2,cnt4-=cnt2,cnt2=a[++cnt];
        else if(c[cnt]!=c[cnt3])ans+=cnt4,cnt2-=cnt4,cnt4=a[--cnt3];
        else{ sum=min(cnt2,cnt4);cnt2-=sum,cnt4-=sum;}
        if(cnt2==0)cnt2=a[++cnt];
        if(cnt4==0)cnt4=a[--cnt3];
    }
    cout<<ans;
    return 0;
}