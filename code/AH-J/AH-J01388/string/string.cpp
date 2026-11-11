#include <bits/stdc++.h>
using LL=long long;
using namespace std;
int n;
LL a[200010];
LL sum;
char c[200010];
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        LL b;
        char c;
        cin>>b>>c;
        s+=b*c;
    }
    LL len=s.size();
    LL l=0,r=len-1,m=(l+r)/2;
    for(int i=m,j=m+(len%2==1?2:1);i>=0;i--){
        if(s[i]!=s[j])sum++;
        j++;
        if(j>=len)break;
    }
    cout<<sum;
    return 0;
}
