#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int t,a[N];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>t>>t;
    while(t--){
        int n,d,k=-1,cnt=0;cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(a[i]>d) k=i;
        }
        if(k==-1){
            cout<<0<<endl;
            continue;
        }
        int c=d/(a[2]-a[1]);
        for(int i=k;i<=n;i++){
            if((i-1)%c!=0&&a[i]%d!=0) cnt++;
        }
        cout<<cnt<<endl;
    }
    return 0;
}
