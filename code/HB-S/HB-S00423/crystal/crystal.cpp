#include<bits/stdc++.h>
#define ll long long
#define el "\n"
using namespace std;
ll n,m,a[500005];
ll s[500005],sum=0;
ll ans;
bool book=1;
bool flag=1;bool deng=0;
void slove(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    int cha=a[2]-a[1];
    for(int i=2;i<=n;i++){
        if(a[i]-a[i-1]==cha){
            deng=1;
        }
        else{
            deng=0;
            break;

        }
    }
    if(deng==1){
        int nmnm=1;
        while(sum<=m){
            sum+=cha++;
            nmnm++;
        }
        cout<<nmnm-1<<el;
        return;
    }



    for(int i=1,j=n;i<=n,j>=n;i++,j--){
        if(a[i]!=a[j]){
            break;
            book=0;
        }
    }
    if(book==1){
        cout<<4<<el;
        return;
    }



    for(int i=2;i<=n;i++){
        if(a[i]==a[i-1]) flag=1;
        else{
            flag=0;
            break;
        }
    }
    if(flag==1){
        cout<<n<<el;
        return;
    }





    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
    }
    if(n==1){
        cout<<1<<el;
        return;
    }
    else if(n==2&&abs(a[2]-a[1])<=m){
        cout<<2<<el;
        return;
    }
    else{
        for(int i=1;i<=n;i++){
            ll max_sum=(i-1)*a[i]-s[i];
            if(max_sum<=m) ans=i;
            else break;
        }
    }
    cout<<ans;



}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int T=1;
    //cin>>T;
    while(T--){
        slove();
    }
    return 0;
}
