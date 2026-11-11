#include<bits/stdc++.h>
using namespace std;
int c,q,n,d,cnt;
int a[2000005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>q;
    while(q--){
        int cnt=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        sort(a+1,a+n+1);
        for(int i=1;i<=n-3;i++){
            if(a[i+3]-a[i+1]<=d&&a[i+3]-a[i+2]<=d&&a[i+1]-a[i]<=d&&a[i+2]-a[i]<=d){
                cnt++;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
