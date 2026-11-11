#include<bits/stdc++.h>
using namespace std;
string s;
int n,cnt;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        int t;
        char a;
        cin>>t>>a;
        for(int j=0;j<t;j++){
            s+=a;
        }
    }
    for(int i=0;i<s.size()/2;i++){
        if(s[i]!=s[s.size()-i-1]){
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
