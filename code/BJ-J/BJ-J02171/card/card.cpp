#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
ll n, m;
vector<ll> a, lst, all;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin>>n>>m;
    a.assign(n+1, 0);
    all.assign(n+1, 0);
    for(int i = 1;i<=n;i++)cin>>a[i];
    for(int i = 1;i<=n;i++){
        lst.assign(m+1, -1);
        for(int j = i;j<=n;j++){
            if(lst[a[j]]==-1){
                lst[a[j]] = j;
                all[a[j]]++;
            }else{
                for(int k = j-1;k>lst[a[j]];k--){
                    all[a[k]]--;
                }
            }
        }
        // for(int j = 1;j<=m;j++){
        //     cout<<all[j]<<' ';
        // }cout<<endl;
    }for(int i = 1;i<=m;i++){
        cout<<all[i]<<' ';
    }cout<<endl;
}/*
4 3
1 2 1 3
*/