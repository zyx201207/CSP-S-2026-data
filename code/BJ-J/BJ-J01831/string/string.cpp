#include<bits/stdc++.h>
using namespace std;
int n;
string s;
long long cnt;
long long hw(string s){
    for(int i=0,j=s.size()-1;i<=j;i++,j--)if(s[i]!=s[j])cnt++;
    return cnt;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        int a;
        char c;
        cin>>a>>c;
        for(int j=1;j<=a;j++)s+=c;
    }
    cout<<hw(s);
    return 0;
}
