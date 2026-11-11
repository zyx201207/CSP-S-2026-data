#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
string s;
int n,sum=0;
int a[N];
char b[N];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    s+='1';
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
    }
    for(int i=1;i<=n;i++){
        int x=a[i];
        for(int j=1;j<=x;j++){
            s+=b[i];
            sum++;
        }
    }
    int cnt=0;
    for(int i=1;i<=sum/2;i++){
        if(s[i]!=s[sum-i+1]) cnt++;
    }
    cout<<cnt;
    return 0;
}
