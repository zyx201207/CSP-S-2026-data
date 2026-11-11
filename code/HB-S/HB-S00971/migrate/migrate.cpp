#include<bits/stdc++.h>
using namespace std;
long long c,t,s[1000005],n,d,a[10000005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        cin>>n>>d;
        long long l=0;
        for(int j=1;j<=n;j++){
            cin>>s[j];
            for(int o=1;o<=d;o++){
                if(j<=3) break;
                if(s[o]<d) continue;
                a[j]+=s[o];
            }
        }
        for(int j=1;j<=n;j++){
            if(a[j]>=2) l++;
        }
        cout<<l<<'\n';
    }
    return 0;
}
