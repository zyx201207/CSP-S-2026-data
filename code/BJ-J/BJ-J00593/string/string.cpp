#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int n,a[maxn],ans;
string s;
char c;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    s+='A';
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c;
        for(int j=1;j<=a[i];j++){
            s+=c;
        }
        a[i]+=a[i-1];
    }
    for(int i=1;i<=(a[n]/2);i++){
        if(s[i]!=s[a[n]+1-i])ans++;
    }
    cout<<ans;
    return 0;
}