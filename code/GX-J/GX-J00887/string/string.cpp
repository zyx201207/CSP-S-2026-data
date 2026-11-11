#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

int main(){
    freopen("string.cpp","r",stdin);
    freopen("string.cpp","w",stdout);
    int n;
    unsigned long long l=0;
    string s;
    cin>>n;
    long long a;
    char c;
   for(int i=1;i<=n;i++){
        cin>>a>>c;
        l+=a;

        for(int j=1;j<=a;j++){
            s+=c;
        }
   }
   bool flag=1;
    for(unsigned long long i=0;i<l/2;i++){
        if(s[i]!=s[l-i-1]){
            flag=0;
            break;
        }
    }
    unsigned long long ans=0;
    if(flag){
        cout<<0;
        return 0;
    }else{
        for(unsigned long long i=0;i<l/2;i++){
            if(s[l]!=s[l-i-1]){
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}

