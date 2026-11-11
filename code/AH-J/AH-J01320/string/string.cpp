#include<bits/stdc++.h>
using namespace std;
long long n,l[200005],cnt=0;
string s[200005],a="";
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
         cin>>l[i]>>s[i];
         for(int j=1;j<=l[i];j++){
            a+=s[i];
         }
    }
    long long l=a.size();
    for(int i=0;i<l/2;i++){
        if(a[i]!=a[l-1-i]){
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
