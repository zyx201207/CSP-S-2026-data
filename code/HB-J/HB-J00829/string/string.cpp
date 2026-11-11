#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;cin>>n;
    if(n==1) cout<<0;
    else if(n==2){
        int a,b;cin>>a>>b;
        char s,s1;cin>>s>>s1;
        if(s==s1) cout<<0;
        else cout<<min(a,b);
    }else if(n<=10){
        long long s;
        for(int i=1;i<=n;i++){
            long long x;
            s+=x/5;
        }
        cout<<s;
    }
    return 0;
}
