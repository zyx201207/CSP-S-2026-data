#include<bits/stdc++.h>
using namespace std;
const int N=2e6+7;
int t;
int n,d;
int ch;
int c;
int z[N];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>z[i];
        }
        ch=z[2]-z[1];
        if(d<ch*2){
            cout<<0<<endl;
        }
        else{
            int num=0;
            for(int i=1;i<=n-(d/ch);i++){
                num+=i;
            }
            cout<<num<<endl;
        }
    }
    return 0;
}
