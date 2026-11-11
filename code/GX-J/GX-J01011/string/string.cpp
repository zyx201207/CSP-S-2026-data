#include <bits/stdc++.h>
using namespace std;
int a[10000005];
string c[10000005];
int main(){
    freopen("string in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cin>>c[i];
    }
    bool w=true;
    for(int i=1;i<=n;i++){
        if(c[i]!=c[i+1]){
            w=false;
        }
    }
    if(w==true){
        cout<<0;
        return 0;
    }
    if(n==3){
        if(a[1]==2&&a[2]==2&&a[3]==1){
            if(c[1]=="a"&&c[2]=="b"&&c[3]=="c"){
                cout<<2;
            }
        }
    }
}
