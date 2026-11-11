#include<bits/stdc++.h>
using namespace std;
long long a[2000010];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.in","w",stdout);
    long long c,n,t,d;
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        int cha=a[2]-a[1];
        int fcnt=d/cha;
        if(fcnt==0||fcnt==1){
            cout<<0<<endl;
        }else{
            cout<<(long long)(n-2*fcnt+1)<<endl;
        }
    }
    return 0;
}
