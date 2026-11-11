#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int c,t;
long long n,d;
long long l[N];

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cin>>c>>t;
    for(int h=1;h<=t;h++){
        bool is=1;
        long long c=0;
        cin>>n>>d;
        memset(l,0,sizeof(l));
        for(int i=1;i<=n;i++) {
            cin>>l[i];
            if(c==2) c=l[2]-l[1];
            if(c>2){
                if(l[i]-l[i-1]!=c) is=0;
            }
        }
        if(is){
            if(d>=c*2){
                cout<<n-3<<endl;
                continue;
            }
        }
        cout<<0<<endl;
    }

    return 0;
}