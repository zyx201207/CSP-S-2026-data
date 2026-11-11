#include<bits/stdc++.h>
using namespace std;
long long m[200000];
char s[200000];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    cin>>n;
    long long he=0;
    for(long long i=0;i<n;i++){
        cin>>m[i]>>s[i];
        he+=m[i];
    }
    bool p=true;
    for(long long i=1;i<n;i++){
        if(s[i]!=s[i-1]){
            p=false;
            break;
        }
    }
    if(p){
        cout<<0;
    }else{
        long long ans=he/2;
        cout<<ans;
    }
    return 0;
}
