#include<bits/stdc++.h>
using namespace std;

int n,cnt;
string s;
//??
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    cin>>n;
    for(int i=1;i<=n;i++){
        char c;
        int m;
        cin>>m>>c;
        s.append(m,c);
    }
    for(int i=s.size()-1;i>s.size()/2;i--){
        if(s[i]!=s[s.size()-i-1]){
            s[i]=s[s.size()-i-1];
            cnt++;
        }
    }
    cout<<cnt;

    return 0;
}
