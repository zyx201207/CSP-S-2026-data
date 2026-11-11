#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,cnt=0,ans=0;
struct stc{
    ll s;
    char c;
}a[200005];
stc b[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(ll i=1;i<=n;i++){
        cin>>a[i].s>>a[i].c;
        cnt+=a[i].s;
    }
    bool flag=0;
    if(cnt%2==1){
        flag=1;cnt++;
    }
    ll cnt2=0,j=0;
    for(ll i=1;i<=n&&cnt2<cnt/2;i++){
        cnt2+=a[i].s;j++;
    }
    if(flag){
        a[j].s--;
        cnt-=2;
    }
/*    for(ll i=1;i<=n;i++){
        for(ll l=1;l<=a[i].s;l++)
            cout<<a[i].c<<" ";
    }*/
    ll cnt3=cnt2-cnt/2;
    ll k=0;
    for(ll i=n;i>j;i--){
        k=n-i+1;
        b[k].s=a[i].s;
        b[k].c=a[i].c;
    }
    if(cnt3!=0){
        k++;
        b[k].s=cnt3;
        b[k].c=a[j].c;
        a[j].s=a[j].s-cnt3;
    }
    ll ki=1,ji=1;
    while(ki<=k&&ji<=j){
        ll wi=min(b[ki].s,a[ji].s);
        if(b[ki].c!=a[ji].c){
            ans+=wi;
        }
        b[ki].s-=wi,a[ji].s-=wi;
        if(b[ki].s==0)ki++;
        if(a[ji].s==0)ji++;
//        cout<<"R:"<<wi<<"\n";
    }
//    cout<<cnt<<" "<<cnt2<<" "<<cnt3<<" "<<j<<" "<<k<<"\n";
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
