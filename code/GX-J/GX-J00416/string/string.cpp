#include<bits/stdc++.h>
using namespace std;
long long n,s,x,f;
char a;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x>>a;
        char b='1';
        if(a==b) f=1;
        else f=0;
        b=a;
        s+=x;
    }
    if(f==1) cout<<0;
    else cout<<s/2;


return 0;
}
