#include<bits/stdc++.h>
using namespace std;
#define int long long
int x,y,n,ans,cnt;
char a;
string s;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    while(n--){
        cin>>x>>a;
        for(int i=1;i<=x;i++)
            s[cnt+i]=a;
        cnt+=x;
    }
    for(int i=1,j=cnt;i<=cnt/2;i++,j--)
        if(s[i]!=s[j])ans++;
    cout<<ans;
    return 0;
}
