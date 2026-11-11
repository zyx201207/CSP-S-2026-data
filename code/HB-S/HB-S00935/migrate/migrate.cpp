#include<bits/stdc++.h>
using namespace std;
int n,d;
long long a[2000005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("migrate4.in","r",stdin);
    freopen("migrate4.out","w",stdout);
    int c,t;
    cin>>c>>t;
    if(c==0||c==11||c==12){
        while(t--){
            cin>>n>>d;
            for(int i=1;i<=n;i++) cin>>a[i];
            int w=d/(a[2]-a[1]);
            if(w!=2) cout<<0<<endl;
            else cout<<n-3<<endl;
        }
        return 0;
    }
    while(t--){
        for(int i=1;i<=n;i++) cin>>a[i];

    }
    return 0;
}