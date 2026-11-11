#include<iostream>
#include<string>
using namespace std;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,sz=0,ans=0;
    cin>>n;
    for(int i=0;i<n;i++){
        long long a;string c;
        //cout<<"cin"<<i<<endl;
        cin>>a>>c;
        sz+=a;
        for(int j=0;j<a;j++)s.append(c);
    }for(int i=0;i<sz/2;i++){
        if(s[i]!=s[sz-1-i]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
