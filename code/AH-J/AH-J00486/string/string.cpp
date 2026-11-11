#include<bits/stdc++.h>
using namespace std;
void solve();
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    solve();
    return 0;
}
#define int long long
const int N=2e5+10;
int a[N];
char c[N];
void solve(){
    int n,len=0;
    cin>>n;
    string s;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        len+=a[i];
        for(int j=1;j<=a[i];j++) s+=c[i];
    }
    int ret=0;
    for(int i=0,j=len-1;i<=len/2 && j>=len/2;i++,j--){
        if(s[i]!=s[j]){
            ret++;
        }
    }
    cout<<ret<<"\n";
    return;
}
