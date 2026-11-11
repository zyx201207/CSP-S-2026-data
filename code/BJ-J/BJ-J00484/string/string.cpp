#include<bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int N=2e5+10;
ll n,a[N],cnt,sum;
string s;
char c[N];
int main(){
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        char y;
        cin>>x>>y;
        while(x--) s+=y;
    }
//    cout<<s<<'\n';
    for(int i=0;i<=s.size()/2;i++){
        //cout<<i<<' '<<s.size()-i-1<<'\n';
        if(s[i]!=s[s.size()-i-1]) s[s.size()-i-1]=s[i],cnt++;
    }
    cout<<cnt;
    return 0;
}
