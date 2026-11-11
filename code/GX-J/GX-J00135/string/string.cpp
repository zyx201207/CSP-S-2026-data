#include <bits/stdc++.h>
using namespace std;
string s[200001];
long long n,ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    int m;
    char c;
    for(int i=1;i<=n;i++){
        cin >> m >> c;
        for(int j=1;j<=m;j++){
            s[i]+=c;
        }
    }int l=0,r=s[n].size()-1,a=1,b=n;
    while(a!=b||r-l>0){
        if(s[a][l]!=s[b][r])ans++;
        l++;
        r--;
        if(l==s[a].size()){
            l=0;
            a++;
        }if(r==-1){
            b--;
            r=s[b].size()-1;
        }
    }cout << ans;
}
