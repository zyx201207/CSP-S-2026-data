#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string x,y,s;
    int n,cnt=0;
    cin>>n;
    for(int i=0;i<=n;i++)
        cin>>y>>s;
    for(int i=s;i<=y;i++){
        cin>>s[i];
        if(s[0]==s[i]) cnt=0;
        else if(s[0]!=s[i]){
            s[i]=s[0];
            cnt++;

        }
        else if(s[0]!=s[i]&&s[1]!=s[i-1]){
            s[i]=s[0];
            s[i-1]=s[1];
            cnt+=2;
        }
    }
    cout<<cnt;
    return 0;
}
