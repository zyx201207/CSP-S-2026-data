#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int n,m;
    string a;
    string b;
    cin>>n>>a>>m>>b;
    if(n==m){
        cout<<1;
        if(a[0]==b[0]&&a[1]==b[1]){
            cout<<1;
            if(a[2]+b[2]!=135){
                cout<<1;
                if(a[2]+1==b[2]||a[2]-1==b[2]){
                    cout<<1;
                }else cout<<0;
            }else cout<<0;
        }else cout<<0;
    }else cout<<0;
    return 0;
}
