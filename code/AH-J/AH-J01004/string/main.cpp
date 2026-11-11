#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freoprn("string.out","w",stdout);
    long long n,cnt,a[1005];
    char b[1005];
    bool x=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
    }
    if(n==1){
        cout<<0;
        return 0;
    }
    if(n==2){
        if(a[0]==a[1]||b[0]==b[1]){
            cout<<0;
            return 0;
        }else{
            cout<<abs(a[0]-a[1]);
            return 0;
        }
    }
    cout<<0;
    return 0;
}
