#include<bits/stdc++.h>
using namespace std;
string a;
int t;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>t;
    while(t--){
        long long s;
        char a1;
        cin>>s>>a1;
        while(s--)a+=a1;
    }
    long long s=!(a.size()%2),ans=0,x=a.size()/2,x1=x+s;
    while(x!=0){

        x--,x1++;
        if(a[x]!=a[x1])ans++;
    }
    cout<<ans;
    return 0;
}
