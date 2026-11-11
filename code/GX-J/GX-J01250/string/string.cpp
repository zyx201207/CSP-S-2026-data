#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    int a[1000005];
    char c[1000005];
    cin>>n;
    string s,t;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    for(int i=1;i<=n;i++){
        t=c[i];
    }
        for(int j=n;j>=1;j--){
            s=c[j];
        }
        if(s==t){
            cout<<0;
        }

    return 0;
}
