#include<iostream>
#include<algorithm>
using namespace std;
int x[2000002];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        int n,d,s=0;
        cin>>n>>d;
        for(int i=0;i<=n;++i){
            cin>>x[i];
        }
        for(int i=0;i<n;++i){
            for(int j=i+1;j<n;++j){
                if(x[j]-x[i]<=d){
                    ++s;
                }
            }
        }
        cout<<s;
    }
    return 0;
}
