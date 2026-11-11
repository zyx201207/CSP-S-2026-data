#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[200010],ans=0,d=0;
char c[200010];
vector<char> s;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        for(int j=1;j<=a[i];j++)s.push_back(c[i]);
    }
    if(s.size()%2==1)d=(s.size()-1)/2;
    else d=s.size()/2;
    for(int i=0;i<d;i++){
        if(s[i]!=s[s.size()-1-i]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
