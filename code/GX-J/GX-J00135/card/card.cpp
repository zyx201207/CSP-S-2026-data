#include <bits/stdc++.h>
using namespace std;
vector <int> v;
int a[300005],ans[300005];
int n,m;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","r",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }int t=1;
    while(t<=n){
        for(int i=t;i<=n;i++){
            for(int j=0;j<v.size();j++){
                if(a[i]==v[j]){
                    while(v.size()>j) v.pop_back();
                    break;
                }
            }v.push_back(a[i]);
        }while(v.size()){
            ans[v.back()]++;
            v.pop_back();
        }t++;
    }for(int i=1;i<=m;i++) cout << ans[i]<<" ";
}
