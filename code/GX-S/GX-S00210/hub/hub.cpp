#include<bits/stdc++.h>
using namespace std;
int n,m,a[2000001],c,t;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>m;
        for(int i=0;i<2*n-2;i++){
            cin>>a[i];
        }cout<<(n-1)/2+1<<endl;
    }
    fclose(stdin);
    fclose(stdout);
}
