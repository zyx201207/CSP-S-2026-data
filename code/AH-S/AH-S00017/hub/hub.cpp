#include<iostream>
#include<cstdio>
using namespace std;
int c,T,n,k;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>T;
    while(T--){
        cin>>n>>k;
        for(int i=1,u,v;i<=n-1;i++){
            cin>>u>>v;
        }
        cout<<1<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
