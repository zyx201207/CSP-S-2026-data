#include<bits/stdc++.h>
using namespace std;
int n,a,idx,ans;
char c;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    while(n--){
        cin>>a>>c;
        while(a--){
            s[++idx]=c;
            //cout<<s[idx];
        }
    }
    //for(int i=1;i<=idx;i++)cout<<s[i];
    for(int i=1;i<=idx/2;i++)if(s[i]!=s[idx-i+1])ans++;
    cout<<ans;
    return 0;
}
