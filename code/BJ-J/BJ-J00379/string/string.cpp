#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn=2e5+10;
ll ans,sum,cur1,cur2;
ll n,a[maxn];
char c[maxn];
stack<pair<ll,char>> stk1,stk2;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        sum+=a[i];
    }
    sum=ll(sum/2);
    //cout << sum << '\n';
    for (int i=1;i<=n;i++){
        if (cur1==sum) break;
        if (a[i]>sum-cur1){
            stk1.push({sum-cur1,c[i]});
            a[i]-=sum-cur1;
            cur1=sum;
        }
        else {stk1.push({a[i],c[i]});cur1+=a[i];}
    }
    for (int i=n;i>=1;i--){
        if (cur2==sum) break;
        if (a[i]>sum-cur2){
            stk2.push({sum-cur2,c[i]});
            a[i]-=sum-cur2;
            cur2=sum;
        }
        else {stk2.push({a[i],c[i]});cur2+=a[i];}
    }
    /*
    while (!stk1.empty()){
        int x=stk1.top().first;char c1=stk1.top().second;stk1.pop();
        cout << x << " " << c1 << '\n';
    }
    cout << '\n';
    while (!stk2.empty()){
        int x=stk2.top().first;char c1=stk2.top().second;stk2.pop();
        cout << x << " " << c1 << '\n';
    }
    */
    while (!stk1.empty()){
        ll x=stk1.top().first;char c1=stk1.top().second;stk1.pop();
        ll y=stk2.top().first;char c2=stk2.top().second;stk2.pop();
        if (x>y){stk1.push({x-y,c1});ans+=(c1==c2?0:y);}
        else if (x==y){ans+=(c1==c2?0:y);}
        else {stk2.push({y-x,c2});ans+=(c1==c2?0:x);}
    }
    cout << ans << '\n';
    return 0;
}
