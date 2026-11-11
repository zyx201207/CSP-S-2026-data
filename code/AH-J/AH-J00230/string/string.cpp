#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1e6+5;

int n;
int a[maxn];
string x;
ll ans;

void init(){
    cin>>n;
    for(int i=1;i<=n;i++){
        ll op;
        string s;
        cin>>op>>s;       
        for(int i=1;i<=op;i++)x+=s; 
    }
}
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);


    ios::sync_with_stdio(0);
    cin.tie(0);
    init();

    for(int i=x.size()/2-1;i>=0;i--){
        if(x[i]!=x[x.size()/2+i])ans++;
    }

    cout<<ans<<"\n";
    return 0;
}