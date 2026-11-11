#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+5;
struct node{
    ll p;
    char c;
    ll h,t;
}a[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ll n;
    cin>>n;
    ll tmp=0,ans=0;
    for(int i=1;i<=n;i++){
        cin>>a[i].p>>a[i].c;
        a[i].h=tmp+1;
        a[i].t=tmp+a[i].p;
        tmp+=a[i].p;
    }
    ll l=1,r=n;
    while(l<=r){
        ll rh=tmp-a[r].t+1;
        ll rt=tmp-a[r].h+1;
        //cout<<"l:"<<l<<" "<<a[l].c<<" "<<a[l].h<<" "<<a[l].t<<endl;
        //cout<<"r:"<<r<<" "<<a[r].c<<" "<<a[r].h<<" "<<a[r].t<<" "<<rh<<" "<<rt<<endl;
        if(a[l].c!=a[r].c){
            ans+=min(a[l].t,rt)-max(a[l].h,rh)+1;
        }
        if(a[l].t>rt){
            r--;
        }else if(a[l].t<rt){
            l++;
        }else{
            l++,r--;
        }
    }
    cout<<ans;
    return 0;
}
