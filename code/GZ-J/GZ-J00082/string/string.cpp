//GZ-J00082 ≥¬”Í«Á
#include <bits/stdc++.h>
using namespace std;
long long ans=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,a,h;
    string c,s;
    cin>>n;
    while(n--){
        cin>>a>>c;
        h+=a;
        for(long long i=1;i<=a;i++)
            s+=c;
    }
    long long l=s.size()-1;
    long long f;
    if(l%2)
        f=l/2+1;
    else
        f=l/2;
    for(long long i=0;i<=f;i++){
        if(s[i]!=s[l-i])
            ans++;
    }
    cout<<ans;
    return 0;
}
