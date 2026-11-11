#include<bits/stdc++.h>
using namespace std;
int n,cnt;
string s="";
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        char c;
        cin>>x>>c;
        for(int j=1;j<=x;j++){
            s=s+c;
        }
    }
    int len=s.size();
    string t=s;
    reverse(t.begin(),t.end());
    for(int i=0;i<len;i++){
        if(s[i]!=t[i]){
            cnt++;
        }
    }
    cout<<cnt/2;
    return 0;
}
