#include<bits/stdc++.h>
using namespace std;
string s[1000];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w,"stdout);
    int n;
    long long cnt=0;
    cin>>n;
    long long a;
    for(int i=1;i<=n;i++){
        cin>>a;
        cin>>s[i];
    }
    for(int i=1;i<n;i++){
        for(int j=n;j>1;j--){
            if(s[i]==s[j]) break;
            if(s[i]!=s[j]){
                cnt++;
                break;
            }
        }
    }
    cout<<cnt*a;
    return 0;
}
