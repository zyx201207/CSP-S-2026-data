#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,a[200005];

    bool b[200005];
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        b[i]=bool(a[i]);
    }
    for(int i=1;i<=200005;i++){
        for(int j=1;j<=200005;j++){
            if(b[i]&b[i+j]==b[i]){
                cout <<b[i];
            }
            else{
                cout <<b[i+j];
            }
        }
    }
    cout<<12;
return 0;
}
