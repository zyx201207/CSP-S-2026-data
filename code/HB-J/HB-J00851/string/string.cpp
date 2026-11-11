#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,a,s=0;
    string c;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a;
        cin>>c[i];

    }
    for(int i=1;i<=n;i++){
        if(c[1]!=c[i]){
            s++;
        }
        else if(c[1]==c[i]){
            cout<<0;
            break;
        }
    }
    cout<<s;
    return 0;
}
