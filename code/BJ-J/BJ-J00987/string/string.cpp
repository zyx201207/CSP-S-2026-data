#include<bits/stdc++.h>
using namespace std;
string a,s;
int n,x,sum,ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin>>n;
    while(n--){
        cin>>x>>a;
        sum+=x;
        for(int i=1;i<=x;i++) s+=a;
    }
    string b=s;
    reverse(s.begin(),s.end());
    if(s==b){cout<<0;return 0;}
    for(int i=0,j=sum-1;i<sum/2;i++,j--){
        if(s[i]!=s[j]) ans++;
    }
    cout<<ans;
    return 0;
}
