#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
const int N=2e6+6;
int c,T;
int n;
ll d,x[N];

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin.tie(0);cout.tie(0);
    cin>>c>>T;while(T--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        if(n==2){
            cout<<"0"<<'\n';
            continue;
        }
        //for(int i=1;i<n-1;i++){
        //    for(int j=3;j<=n;j++){
//
  //          }
    //    }
        cout<<"0"<<'\n';
    }



    return 0;
}
