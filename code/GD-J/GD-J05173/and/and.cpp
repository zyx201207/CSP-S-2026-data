#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int a,s;
    doudle d,f;
    cin>>a>>d>>s>>f;
    if(a==d)cout<<1;
    else cout<<0;
    if(d/10==f/10)cout<<1;
    else cout<<0;
    if(d%10+f%10<=133&&d%10+f%10>=131)cout<<1;
    else if(d%10+f%10==137)cout<<1;
    else cout<<0;
    if(d%10+f%10==131||d%10+f%10==133||d%10+f%10==137)cout<<1;
    else cout<<0;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
