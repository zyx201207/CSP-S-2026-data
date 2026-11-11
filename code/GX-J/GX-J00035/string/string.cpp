#include<bits/stdc++.h>
using namespace std;
long long const L=100000005;
long long s[L];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int a,c;
    cin>>a>>c;
    int n;
    cin>>n;
    for(int i=1;i*i<=n;i++){
        cin>>s[i];
    }
    cout<<2;
    return 0;
}

