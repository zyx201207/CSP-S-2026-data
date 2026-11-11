#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char b[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();
    int n;
    string s="",t="";
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
        for(int j=1;j<=a[i];j++){
            s+=b[i];
        }
    }
    for(int i=0;i<s.size();i++){
        t=s[i]+t;
    }
    long long l=s.size(),cnt=0;
    l/=2;
    for(int i=0;i<l;i++){
        if(s[i]!=t[i]){
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
