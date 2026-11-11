#include<bits/stdc++.h>
using namespace std;
string s="";
int n;
long long ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        int ans;
        char a;
        cin>>ans>>a;
        while(ans--){
            s=s+a;
        }
    }
    char a[1000000];
    for(int i=0;i<s.size();i++) a[i]=s[i];
    for(long long i=0;i<s.size();i++){
        if(a[i]!=a[s.size()-1-i]){
            a[i]=a[s.size()-1-i]=s[i];
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
