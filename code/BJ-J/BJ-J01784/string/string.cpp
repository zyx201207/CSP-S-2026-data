#include <bits/stdc++.h>
using namespace std;
int n,a,c,ans=0;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%d\n",&n);
    for(int i=1;i<=n;i++){
        scanf("%d ",&a);
        scanf("%c",&c);
        for(int j=1;j<=a;j++)s+=c;
    }
    for(int i=0;i<s.size()/2;i++){
        if(s[i]==s[s.size()-i-1])continue;
        else ans++;
    }
    printf("%d",ans);
    return 0;
}
