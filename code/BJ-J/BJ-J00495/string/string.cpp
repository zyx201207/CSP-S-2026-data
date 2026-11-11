#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=2*1e5+5;
int n;
int a[MAXN]={0},ans=0;
char c[MAXN]="";
std::string str="";
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i]>>c[i];
        for(int j=1;j<=a[i];++j){
            str+=c[i];
        }
    }
    for(int i=0;i<str.size()/2;++i){
        if(str[i]!=str[str.size()-1-i])ans++;
    }
    cout<<ans<<'\n';
    return 0;
}
