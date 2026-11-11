#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    cin>>n;
    string s;
    long long ans=0;
    for(long long i=0;i<n;i++){
        long long a;
        char c;
        cin>>a>>c;
        ans+=a;
        for(long long j=0;j<a;j++){
            s+=c;
        }
    }
    long long s1=s.size();
    string a="";
    for(long long i=s1-1;i>=0;i--){
        a+=s[i];
    }
    long long b=0;
    for(long long i=0;i<s1;i++){
        if(s[i]==a[i]){
            b++;
        }
    }
    if(b==s1){
        cout<<0<<endl;
        return 0;
    }else{
        cout<<ans/2<<endl;
        return 0;
    }
    return 0;
}
