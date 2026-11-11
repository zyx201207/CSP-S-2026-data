#include<bits/stdc++.h>
using namespace std;
char c;
string ch;
int cnt=0,ans;
int n,k;
int main(){
    freopen("string.in","r",stdin);   freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>k>>c;
        for(int i=1;i<=k;i++){
            ch[++cnt]=c;
        }
    }
    for(int i=1;i<=cnt/2;i++){
        if(ch[i]!=ch[cnt-i+1])ans++;
    }
    cout<<ans<<endl;
    fclose(stdin);
    fclose(stdout);
}
