#include<bits/stdc++.h>
using namespace std;
int n,ans,a;
char c[10000005];
string s,ds;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> a ;
    for(int i=1;i<=a;i++){
        cin >> n >>c[i];
        for(int j=1;j<=n;j++){
            s+=c[i];
        }
    }
    reverse(s.begin(),s.end());
    ds=s;
    reverse(s.begin(),s.end());
    for(int i=0;i<s.size();i++){
        if(ds==s){
            cout << "0";
            return 0;
        }
    }
    return 0;
}
