#include<bits/stdc++.h>
using namespace std;
long long ans,n,cnt;
string s;
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        int p;
        char c;
        cin>>p>>c;
        cnt+=p;
        while(p--){
            s+=c;
        }
    }
    for(int i=0;i<cnt;i++){
        if(s[i]!=s[cnt-i-1])
            ans++;
    }
    cout<<ans/2<<endl;
    return 0;
}
