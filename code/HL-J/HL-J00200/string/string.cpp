#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,a[N],c[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s="";
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=a[i];j++){
            s+=c[i];
        }
    }
    int L=s.size();
    for(int i=0;i<L;i++){
        if(s[i]!=s[L+1-i]){
            s[i]=s[L+1-i];
            ans++;
        }
        else{
            continue;
        }
    }
    cout<<ans;
    return 0;
}
