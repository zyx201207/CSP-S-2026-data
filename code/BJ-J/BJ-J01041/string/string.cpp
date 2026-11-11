#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    unsigned long long k;
    string s,s1;
    cin>>n;
    while(n--){
        cin>>k>>s1;
        for(int i=1;i<=k;i++){
            s+=s1;
        }
    }
    int cnt=0;
    for(int i=0;i<s.size()/2;i++){
        if(s[i]!=s[s.size()-i-1]){
            cnt++;
        }
    }
    cout<<cnt;
}
