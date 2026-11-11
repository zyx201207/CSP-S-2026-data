#include <bits/stdc++.h>
using namespace std;
const int INT_M=1e9;
int c,t;
queue<int> qu;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    while(t--){
        int res=0;
        int n,d;
        cin>>n>>d;
        vector<long long>arr{n};
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int dis=arr[1]-arr[0];
        if(d/dis<2){
            cout<<0;
            return 0;
        }

        cout<<res;
    }

    return 0;
}
