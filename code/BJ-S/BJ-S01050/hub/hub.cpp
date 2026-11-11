#include<bits/stdc++.h>
using namespace std;

int n,d;
int v[100010],u[100010];
int main(){
    freopen("hub1.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,q;
    cin>>c>>q;
    while(q--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>v[i]>>u[i];
        }
        int xx=n%2;
        if(xx=0)
        cout<<2<<endl;
        else{
            cout<<1<<endl;
        }
    }
    return 0;
}
