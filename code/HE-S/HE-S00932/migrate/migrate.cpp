#include<bits/stdc++.h>
using namespace std;
signed long long c,t,n,d,x[2000010],dfly[2000010];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t){
        cin>>n>>d;
        for(int i=0;i<n;i++) cin>>x[i];
        if(n==1||n==2||n==3) cout<<0;
        if(n==4&&x[2]-x[0]<=d&&x[3]-x[1]<=d&&x[0]+x[1]+x[2]+x[3]>d) cout<<1;
        int cha=x[2]-x[1];
        int dn=d/cha;
        int ans=n;
        int v=0;
        while(v<dn-1){
            ans-=dn-v;
            v++;
        }
        cout<<ans;
        t--;
    }
    return 0;
}
