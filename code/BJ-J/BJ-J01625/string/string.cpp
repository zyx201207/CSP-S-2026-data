#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int a;
    cin>>a;
    long long ans=0;
    string q="";
    long long p=0;
    char s[200001];
    for(int i=0;i<a;++i){
        int k;
        cin>>k;
        p+=k;
        cin>>s[i];
        for(int j=0;j<k;++j) q+=s[i];
    }
    ++p;
    p/=2;
    for(int z=p+1;z<=2*p;++z){
        if(q[z]!=q[2*z-p]) ans++;
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
