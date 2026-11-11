#include<bits/stdc++.h>
using namespace std;
#define int unsigned long long
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    string s;
    while(n--){
        int a;
        char b;
        cin>>a;
        cin>>b;
        for(int i=1;i<=a;i++){
            s+=b;
        }
    }
    string c=s;
    reverse(s.begin(),s.end());
    int cnt=0;
    for(int i=0;i<s.size();i++){
        if(s[i]!=c[i]){
            cnt++;
        }
    }
    cout<<cnt/2;
    return 0;
}
