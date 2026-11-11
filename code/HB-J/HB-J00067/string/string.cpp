#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    int cnt=0;
    string s;
    cin>>n;
    while(n--){
        int a;
        cin>>a;
        string c;
        cin>>c;
        for(int i=1;i<=a;i++){
            s+=c;
        }
    }
    for(int i=0;i<=s.size()/2;i++){
        if(s[i]!=s[s.size()-1-i])cnt++;
    }
    cout<<cnt;
    return 0;
}
