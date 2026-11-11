#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    string a,b;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }
    int cnt=0;
    for(int i=2;i<=n;i++){
        if(b[i]==b[i-1]) cnt++;
    }
    if(cnt==n-1) cout<<"0";
    return 0;
}
