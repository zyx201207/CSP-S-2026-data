#include<bits/stdc++.h>
using namespace std;
int n,cnt,a;
string c;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>c;
        cnt+=a;
    }
    for(int i=1;i<=n;i++){
        if(c[i]==c[i+1]==c[n]){
            cout<<0;
            break;
        }
    }
    cout<<cnt/2;
    return 0;
}
