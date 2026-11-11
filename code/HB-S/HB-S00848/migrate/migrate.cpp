#include<iostream>
using namespace std;
int c,t,n,d,l[2000000],ans;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int i=0;i<t;++i){
        ans=0;
        cin>>n>>d;
        for(int j=0;j<n;++j)cin>>l[i];
        for(int j=0;j<n-3;++j){
            if(l[j+2]-l[j]<=d&&l[j+3]-l[j+1]<=d&&l[j+3]-l[j]>d)ans++;
        }
        cout<<ans<<'\n';
    }
    return 0;
}
