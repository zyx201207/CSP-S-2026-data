#include<bits/stdc++.h>
using namespace std;
bool f;
int n,m,ans;
string a,k;
string b;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    while(n--){
        cin>>m;cin>>a;
        while(m--){
            b.append(a);
        }
    }
    for(int i=1;i<=n/2;i++){
        if(b[i]!=b[n-i+1]){
            f=1;
            b[n-i+1]=b[i];
            ans++;
        }
    }
    if(f==0){
        cout<<0;
    } else{
        cout<<ans;
    }

    return 0;
}
