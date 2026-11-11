#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s;
    char c;
    int n,a,cnt=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d %c",&a,&c);
        for(int j=1;j<=a;j++) s+=c;
    }
    for(int l=0,r=s.size()-1;l<r;l++,r--)
        if(s[l]!=s[r]) cnt++;
    printf("%d",cnt);
    return 0;
}
