#include <bits/stdc++.h>
using namespace std;
string a;
int cnt;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdin);

    cin>>a;
    int n=a.size();
    for(int i=1;i<=n;i++){
        if(a[i]==a[n-i]){
            cnt++;
        }
        if(cnt=n)cout<<0;

    else{
    cout<<n-cnt;}
    }
return 0;
}
