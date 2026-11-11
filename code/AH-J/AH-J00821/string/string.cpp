#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL a[200010];
char c[200010];
bool check(string s){
    string ss=s;
    reverse(s.begin(),s.end());
    return (ss==s);
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    LL n,ans=0,t=0,x;
    string s="";
    char ch;
    cin>>n;
    for(LL i=1;i<=n;i++){
        cin>>x>>ch;
        if(ch==c[t]) a[t]+=x;
        else{
            a[++t]=x;
            c[t]=ch;
        }
        for(LL j=1;j<=x;j++) s+=ch;
    }
    if(check(s)){
        cout<<0;
        return 0;
    }
    for(LL i=1;i<=t/2;i++){
        if(c[i]==c[1+n-i]) ans+=abs(a[1+n-i]-a[i]);
        else ans+=max(a[1+n-i],a[i]);
    }
    cout<<ans;
    return 0;
}
