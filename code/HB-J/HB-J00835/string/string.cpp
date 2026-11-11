#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using db=double;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int res=0;
    string str="";
    int n;cin>>n;
    for(int i=0;i<n;i++){
        char a;int x;
        cin>>x>>a;
        str+=string(x,a);
    }
    n=str.length();
    for(int i=0;i<n/2;i++){
        if(str[i]!=str[n-1-i]){
            res++;
        }
    }
    cout<<res;
    return 0;
}
//   Secure Contain Protect
//   079 help me!