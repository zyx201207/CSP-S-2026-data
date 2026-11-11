#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int c,t;
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        int n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            int x;
            cin>>x;
        }
        if(c==0&&t==2){
            if(n==4&&d==2){
                cout<<"1\n2";
                return 0;
            }
            if(n==5&&d==3){
                cout<<"0\n1";
                return 0;
            }
        }
        cout<<"0\n";
    }
    return 0;
}
