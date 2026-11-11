#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2000010;
int a[N];
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        int n,d,c;
        bool flag=1;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        if(n==d){
            cout<<0<<"\n";
            continue;
        }
        for(int i=2;i<=n;i++){
            if(i==2){
                c==a[i]-a[i-1];
            }else{
                if(a[i]-a[i-1]!=c){
                    flag=0;
                    break;
                }
            }
        }
        if(flag==0){
            cout<<0<<"\n";
            continue;
        }
        if(d>a[2]-a[1]+1){
            cout<<0<<"\n";
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
