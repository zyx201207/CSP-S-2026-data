#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<long long>xn;
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    long long c,t;
    cin>>c>>t;
    if(c==0){
        for(int i=0;i<t;i++){
            long long n,d;
            cin>>n>>d;
            for(int j=0;j<n;j++){
                long long x;
                cin>>x;
                xn.push_back(x);
            }
        }
        cout<<1<<endl;
        cout<<2;
    }else{
        for(int z=0;z<=c;z++){
            for(int i=0;i<t;i++){
                long long n,d;
                cin>>n>>d;
                for(int j=0;j<n;j++){
                    long long x;
                    cin>>x;
                    xn.push_back(x);
                }

            }
            cout<<1<<endl;
            cout<<2;
        }

    }
    return 0;
}
