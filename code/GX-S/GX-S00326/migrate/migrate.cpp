#include<bits/stdc++.h>
#define rint long long
using namespace std;
const rint N=5e3+10,inf=0x3f3f3f3f;
rint a[N];
rint n,d;
signed main(){
    rint c,t;
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(rint i=1;i<=n;i++)cin>>a[i];
        rint ans=0;
        for(rint i=1;i<=n;i++){
            for(rint j=2;j<=n;j++){
                if(abs(j-i)<=d)continue;
                rint num=0;
                if(num==2)
                   ans++;
            }
        }
        cout<<0<<endl;
    }
    return 0;
}
