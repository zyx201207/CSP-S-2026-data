#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int a,s,d,f;
    cin>>a>>d>>s>>f;
    if(a==s)cout<<1;
    else cout<<0;
    if(d/10==f/10)cout<<1;
    else cout<<0;
    if(d%10+f%10<=137&&d%10+f%10>=135)cout<<1;
    else if(d%10+f%10==141)cout<<1;
    else cout<<0;
    if(d%10+f%10==137||d%10+f%10==135||d%10+f%10==141)cout<<1;
    else cout<<0;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

