#include<bits/stdc++.h>
#define ll long long
#define MAXN 500010
using namespace std;
ll m;
int n;
ll a[MAXN];
ll S[MAXN];
inline int f(int i,int j){
    return (j-i)*a[j]-S[j]+S[i];
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i = 0;i < n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    S[0]=0;
    for(int i = 1;i<n;i++){
        S[i]=S[i-1]+a[i-1];
    }
    ll s = 0;
    int ans=n;
    for(int i = 0;i < n;i++){
        s+=i*(a[i+1]-a[i]);
        if(s>m){
            ans=i+1;
            break;
        }
    }
    
    for(int i = ans;i;i++){
        int t = n-i+1;
        bool has=false;
        for(int j = 0;j < t;j++){
            if(f(j,j+i-1)<=m){
                has=true;
            }
        }
        if(!has){
            cout<<i-1;
            return 0;
        }
    }
    return 0;
}