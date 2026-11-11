#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,a;char c;scanf("%d",&n);
    string s;
    for(int i=0;i<n;i++){
        scanf("%d %c",&a,&c);
        for(int i=0;i<a;i++)s+=c;
    }long long L=s.size(),x(0);
    for(int i=0;L-i-1>=i;i++)if(s[i]!=s[L-i-1])x++;
    printf("%lld",x);
    return 0;
}
