#include<iostream>
#include<string>
#include<cstring>
using namespace std;
long long n,ans=0;
string s,hws;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    long long a[n];char c[n];
    for(long long i=0;i<n;i++){
        cin>>a[i]>>c[i];
        for(long long j=0;j<a[i];j++)s+=c[i];
    }
    for(long long i=s.size()-1;i>=0;i--){
        hws+=s[i];
    }
    if(s==hws)cout<<0<<endl;
    else{
        for(long long i=0;i<s.size()/2;i++){
            if(s[i]!=hws[i])ans++;
        }
        cout<<ans;
    }
    return 0;
}
