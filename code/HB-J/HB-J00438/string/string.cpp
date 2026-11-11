#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;
ll n,cnt;
string s[N];
void solve(){
    cin>>n;
    vector<ll>v(n+1,0);
    for(int i=0;i<n;i++){
        cin>>v[i]>>s[i];
    }
    ll b=0,e=n-1;
    while(b<e){

        if(v[b]>v[e]){
            if(s[b]!=s[e]){
                cnt+=v[e];
                v[b]-=v[e];
                e--;

            }else{
                v[b]-=v[e];
                e--;
            }
        }else if(v[b]==v[e]){
            if(s[b]!=s[e]){
                cnt+=v[b];
                b++;
                e--;
            }else{
                b++,e--;
            }
        }else if(v[b]<v[e]){
            if(s[b]!=s[e]){
                cnt+=v[b];
                v[e]-=v[b];
                b++;
            }else{
                v[e]-=v[b];
                b++;
            }
        }
    }
    cout<<cnt;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int _=1;
    while(_--)solve();
    return 0;
}
