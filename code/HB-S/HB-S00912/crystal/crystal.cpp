#include<bits/stdc++.h>
using namespace std;
#define ll long long

//Neverness to Everness
const int N =500000;

ll n,m,crypower[N],bag[N],cnt[N],ans1,ans2;

void Honkai(){
    for(ll i=1;i<=n;i++){
   //     cout << bag[i]<<endl;
        ll pls=bag[i];
        cnt[pls]++;
    }
    for(ll i=1;i<=n;i++){
        ans1=max(ans1,cnt[i]);
    }
    ans2=max(ans1,ans2);
    memset(cnt,0,N);
}

void Genshin(ll step,ll chance,ll pos){
    //cout <<"step"<<step<<' '<<"chance"<<chance<<' '<<"pos"<<pos<<endl;
    if(pos>n){
        return;
    }
    if(step>m){
        Honkai();
        return;
    }
    if(step==m){
        if(chance>0){
            bag[pos]=crypower[pos]+chance;
        }
        Genshin(step+1,0,pos);
        bag[pos]=0;
    }
    if(chance==0){
        bag[pos]=crypower[pos];
        for(ll i=pos;i<=n;i++){
            bag[i]=crypower[i];
        }
        Honkai();
        // Genshin(step+1,chance,pos+1);
        for(ll i=pos;i<=n;i++){
            bag[i]=0;
        }
    }
    for(int i=0;i<=m;i++){
        if(chance-i<0){
            return;
        }
        bag[pos]=crypower[pos]+i;
        Genshin(step+1,chance-i,pos+1);
        bag[pos]=0;
    }
}

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    cin >>n>>m;
    for(ll i=1;i<=n;i++){
        ll x;
        cin >> x;
        crypower[i]=x;
    }
    Genshin(1,m,1);
    cout << ans2;
    return 0;
}
