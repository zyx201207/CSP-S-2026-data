#include<bits/stdc++.h>
using namespace std;
using ll=long long;
bool a[200005][35];
long long jk[200005];
long long qq[200005];
ll x[35];
string _10_2_tc(ll a,ll is){
    string n="";
    qq[is]=a;
    while(a){
        n+=char(a%2+'0');
        a/=2;
    }
    int y=n.size();
    for(int i=0;i<30-y;i++)n.push_back('0');
    for(int i=0;i<n.size();i++){
        ::a[is][i]=(bool(n[i]-'0') ? 1 : 0);
        x[i]+=bool(n[i]-'0');
    }
    return n;
}
struct iu{
    int i;long long zj;ll pg;
};
bool ls(iu a,iu b){
    return a.pg>b.pg;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ll n,yq;cin>>n>>yq;
    for(int i=0;i<n;i++){
        ll s;cin>>s;_10_2_tc(s,i);
    }
    int maxh=-1;
    for(int i=30;i>=0;i--){
        if(x[i]>=2){
            maxh=i;break;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<35;j++){
            if(a[i][j]==1){
                jk[i]+=x[j];
            }

        }

    }
    if(maxh==-1){
        cout<<0;return 0;
    }
    vector<iu> y;
    for(int i=0;i<n;i++){
        y.push_back({i,qq[i],jk[i]});
    }
    sort(y.begin(),y.end(),ls);
    long long a=y[0].zj;
    for(int i=1;i<yq;i++){
        a&=y[i].zj;
    }
    cout<<a;
    return 0;
}
