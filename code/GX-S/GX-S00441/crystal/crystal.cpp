#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<int> a,b;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    cin>>n>>m;
    if(n%2==1){
        cout<<(n+1)/2;
    }
    if(n%2==0){
        cout<<n/2;
    }
    return 0;
}
