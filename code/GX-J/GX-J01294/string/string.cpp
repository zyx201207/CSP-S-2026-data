#include <bits/stdc++.h>
using namespace std;
const int maxx=1e5;
int n;
bool jk(string a){
    int l=1,r=n-1;
    while(l<r){
        if(a[l]==a[r]){
            l++;
            r--;
        }
        else return false;
    }
    return true;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        int a;
        string c;
        cin>>a>>c;
        if(jk(c)==false){
            cout<<n/2;
        }
        else{
            cout<<0;
        }
    }
    return 0;
}
