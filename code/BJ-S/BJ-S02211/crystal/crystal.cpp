#include<bits/stdc++.h>
using namespace std;
long long n, m;
const int N = 5e5+10;
long long a[N],s[N];
long long ans1[N];
long long ans = 1;
long long ans2 = 0;
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    memset(ans1, 1, sizeof(ans1));
    cin>>n>>m;
    for(int i = 1; i<= n; i++){
        cin>>a[i];
    }
    sort(a+1, a+n+1);
    long long k,xp1 = 0;
    for(int i = 1; i< n; i++){
        k = m;
        ans = 1;
        for(int j = i+1; j<= n; j++){
            long long xp;
            xp = a[j]-a[i];
            if(xp==xp1){
                ans++;
                continue;
            }
            if(xp>k) break;
            else{
                ans++;
                k-=xp;
                xp1 = xp;
            }
        }
        ans1[i] = ans;
    }
    for(int i = 1; i< n; i++){
        //cout<<ans1[i]<<" ";
        if(ans1[i]>ans2){
            ans2 = ans1[i];
        }
    }
    cout<<ans2;
    return 0;
}
