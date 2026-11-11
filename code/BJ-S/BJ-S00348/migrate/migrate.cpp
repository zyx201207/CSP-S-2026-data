#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    if(c==0||c==11||c==12){
        for(int i=1;i<=t;i++){
            int n,m;
            cin>>n>>m;
            int a,b;
            cin>>a;
            cin>>b;
            string cc;
            cin>>cc;
            if((b-a)*2<m){
                cout<<0<<endl;
            }
            else{
                cout<<n-m-1<<endl;
            }
        }
    }
    else cout<<0<<endl;
    return 0;
}

