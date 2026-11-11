#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
ll a[N];
const int M=3e5+5;
ll b[M];
ll c[M];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        memset(b,0,sizeof b);
        stack<ll> desk;
        for(int j=i;j<=n;j++){
            ll k=a[j];
            if(!b[k]){
                b[k]++;
                desk.push(k);
            }else{
                while(!desk.empty() && desk.top()!=k){
                    b[desk.top()]--;
                    desk.pop();
                }
                while(!desk.empty() && desk.top()==k){
                    b[desk.top()]--;
                    desk.pop();
                }
                b[k]++;
                desk.push(k);
            }
        }
        for(int j=1;j<=m;j++){
            if(b[j]) c[j]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<c[i]<<" ";
    }
    return 0;
}
