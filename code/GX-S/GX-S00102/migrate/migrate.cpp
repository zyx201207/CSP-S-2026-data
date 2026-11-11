#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,a,ans;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        ans=0;
        cin>>n>>d;
        for(int i=0;i<n;i++){
            cin>>a;
            if((a-1)%d!=0){
                ans++;
            }
        }
        cout<<(n-1)/2<<endl;
    }
    return 0;
}
