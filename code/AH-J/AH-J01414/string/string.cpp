#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
struct Node{
    LL s;
    char c;
}a[200010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s;
    LL n,cnt=0;
    cin>>n;
    for(LL i=1;i<=n;i++){
        cin>>a[i].s>>a[i].c;
        for(LL j=1;j<=a[i].s;j++){
            s+=a[i].c;
        }
    }
    sort(s.begin(),s.end());
    if(s[1]!=s[n]) {s[n]=s[1];cnt++;}
    for(LL i=1;i<=n;i++){
        if(s[i]!=s[n-i]){
            s[n-i]=s[i];
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}

