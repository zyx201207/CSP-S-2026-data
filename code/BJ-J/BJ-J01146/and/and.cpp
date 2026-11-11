#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[223456];
int sc[223456];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for (int i = 1;i<=n;i++){
        cin>>a[i];
    }
    int ans = 0;
    for (int dig = 29;dig>=0;dig--){
        int cnt = 0;
        for (int i = 1;i<=n;i++){
            if (sc[i]) continue;
            if ((a[i]&(1<<dig))>0){
                cnt++;
            }
        }
        if (cnt>=m){
            ans+=1<<dig;
            for (int i = 1;i<=n;i++){
                if ((a[i]&(1<<dig))==0){
                    sc[i] = 1;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
