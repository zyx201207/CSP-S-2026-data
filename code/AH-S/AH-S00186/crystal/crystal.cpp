#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll m;
ll a[500005],b[500005];
void solve1(){
    for(int i=n;i>=1;i--){
        b[i]=b[i+1]+(n-i);
    }
    for(int i=1;i<=n;i++){
        if(m>=b[i]){
            cout<<n-i+1<<endl;
            return;
        }
    }
}
void solve2(ll x){
    for(int i=n;i>=1;i--){
        b[i]=b[i+1]+(n-i)*x;
    }
    for(int i=1;i<=n;i++){
        if(m>=b[i]){
            cout<<n-i+1<<endl;
            return;
        }
    }
}
void solve3(){
    int max_n=1;
    for(int i=n;i>=1;i--){
        int k=1;ll cry=0;
        for(int j=i-1;j>=1;j--){
            if(cry+(a[i]-a[j])>m){
                break;
            }
            cry+=(a[i]-a[j]);
            //cout<<a[i]<<"-"<<a[j]<<endl;
            k++;
        }
        max_n=max(max_n,k);
    }
    cout<<max_n<<endl;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    bool b1=1,b2=1;
    ll cha=0,cha2=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        if(a[i]!=i) b1=0;
        if(i==1) continue;
        else if(i==2){
            cha=a[i]-a[i-1];
            cha2=a[i]-a[i-1];
        }else cha2=a[i]-a[i-1];
        if(cha!=cha2) b2=0;
    }
    if(b1){
        solve1();
    }else if(b2){
        solve2(cha);
    }else{
        solve3();
    }
    return 0;
}
