#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    cin>>n;
    string s1,s2;
    for(long long i=0;i<n;i++){
        long long a;
        string c;
        cin>>a>>c;
        for(long long j=0;j<a;j++){
            s1=s1+c;
        }
    }
    for(long long i=0;i<s1.length();i++){
        s2[i]=s1[s1.length()-i-1];
    }
    long long ans=0;
    for(long long i=0;i<s1.length();i++){
        if(s1==s2){
            break;
        }
        if(s1[i]!=s2[i]){
            s2[i]=s1[i];
            s1[s1.length()-i-1]=s1[i];
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
