#include<bits/stdc++.h>
using namespace std;
int x[2000005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int c,t;
    cin>>c>>t;
    while(t--){
        int n,d;
        cin>>n>>d;
        for(int i=0;i<n;++i){
            cin>>x[i];
        }
        long long cnt=0;
        for(int j=0;j<n-1;++j){
            int k=j+2;
            if(x[j+1]-x[j]<=d&&x[k]-x[j+1]<=d&&x[k]-x[j]<=d){
                cnt++;
            }
        }
        cout<<cnt<<"\n";
    }
    return 0;
}
