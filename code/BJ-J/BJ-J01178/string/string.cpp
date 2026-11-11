#include<bits/stdc++.h>
using namespace std;
int n;
string s;
long long cnt;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        int a;
        string b;
        cin>>a>>b;
        for(int j=1;j<=a;j++){
            s+=b;
        }
    }
    s="="+s;
    for(int i=1;i<=s.size()/2;i++){
        if(s[i]!=s[s.size()-i])cnt++;
    }
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
