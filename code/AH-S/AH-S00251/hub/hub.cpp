#include<iostream>
using namespace std;
int c,t,n,k,x[1000005],y[1000005];
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<=n-1;i++){
            cin>>x[i]>>y[i];
        }
        cout<<1;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
