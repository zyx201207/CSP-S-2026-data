#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n,a;
ll cnt;
char c;
string s;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>c;
        for(int j=1;j<=a;j++) s+=c;
    }
    for(int i=0,j=s.size()-1;i<j;i++,j--){
        if(s[i]!=s[j]) cnt++;
    }
    cout<<cnt;
    return 0;
}
