#include<bits/stdc++.h>
using namespace std;
long long a[1000005], n, p;
string b[1000005], s, s2;
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
        s+=b[i];
        if(i==1){
            p=a[1];
        }
        if(p!=a[i]&&p!=-1){
            p=-1;
        }
    }
    if(p!=-1){
        cout<<n/2*p;
        return 0;
    }
    cout<<0;

    return 0;
}
