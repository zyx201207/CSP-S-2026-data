#include<bits/stdc++.h>
using namespace std;
long long n,a[200005];
char c[200005];
unsigned long long ans=0;
long long b[27];
string s;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=27;i++)b[i]=0;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        b[c[i]-'a'+1]++;
    }
    int e=0;
    for(int i=1;i<=n;i++)if(b[i]>=1)e++;
    if(e==1){
        cout<<0;
        return 0;
    }
    int t=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=a[i];j++){
            s[t]=c[i];
            t++;
        }
    }
    for(int i=1;i<=n;i++){
        if(s[i]!=s[n-i+1]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
