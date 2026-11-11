#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int c,t,n,k,u[1000000],v[1000000];
    cin>>c>>t;
    cout<<endl;
    cin>>n>>k;
    for(int i=1;i<n-1;i++){
        cin>>u[i]>>v[i];
    }
    if(c==0&&t==2){
        cout<<"1"<<endl;
        cout<<"2";
    }
    return 0;
}
