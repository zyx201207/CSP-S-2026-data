#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e5+10;
struct stu{
    ll x;
    char c;
}a[N];
ll n,sum;
string t;
int main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].x>>a[i].c;
        sum+=a[i].x;
    }
    if(sum<=10000000){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=a[i].x;j++){
                t+=a[i].c;
            }
        }
        ll ans=0;
        for(int i=0;i<t.size()/2;i++){
            if(t[i]!=t[t.size()-i-1]){
                ans++;
            }
        }
        cout<<ans;
    }else{
        ll ans=0;
        for(int i=1,j=n;i<=j;){
            if(a[i].c!=a[j].c){
                ans+=min(a[i].x,a[j].x);
            }
            if(a[i].x>a[j].x){
                a[i].x-=a[j].x;
                j--;
            }else if(a[i].x<a[j].x){
                a[j].x-=a[i].x;
                i++;
            }else{
                i++,j--;
            }
        }
        cout<<ans;
    }
    return 0;
}
/*
5
2 a
3 b
4 c
5 s
6 a
*/
