#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+2;
int n,size,a[maxn],ans;
string s,s1,s2;
char c[maxn];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        for(int j=1;j<=a[i];j++)s+=c[i];
    }
    int x=s.size();
    int mid=x/2;
    for(int i=0;i<mid;i++) s1+=s[i];
    for(int i=x;i>x-mid;i--) s2+=s[i];
    for(int i=0;i<mid;i++)
        if(s1[i]!=s2[i]) ans++;
    cout<<ans<<'\n';
    return 0;
}
