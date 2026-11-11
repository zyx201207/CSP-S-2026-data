#include<bits/stdc++.h>
using namespace std;
int c,t,k=1;
int main(){
    freopen("migrate","r",stdin);
    freopen("migrate","w",stdout);
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        int n,d,x[2000001];
        cin>>n>>d;
        for(int j=1;j<=n;j++){
            cin>>x[j];
        }
        cout<<k<<endl;
        k++;
    }
    return 0;
}
