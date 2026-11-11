#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
bool b,b2;
struct node{
    int a;
    char c;
}str[200010];
int amax;
int t[256];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>str[i].a>>str[i].c;
        amax=max(amax,str[i].a);
        t[str[i].c]++;
    }
    int cnt=0;
    for(char i='a';i<='z';i++){
        if(t[i]!=0) cnt++;
    }
    if(cnt==1){
        cout<<0;
        return 0;
    }
    if(n<=1){
        cout<<0;
        return 0;
    }
    if(n<=2){
        cout<<min(str[1].a,str[2].a);
        return 0;
    }
    //20
    if(amax<=1){
         if(cnt==n){
            cout<<n-1;
        }
        int ans=0;
        int l=1,r=n;
        while(l<r){
            if(str[l].c!=str[r].c) ans++;
            l++;
            r--;
        }
        cout<<ans;
        return 0;
    }
    string s;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=str[i].a;j++){
            s+=str[i].c;
        }
    }
    s=" "+s;
    int ans1=0;
    int l=1,r=s.size()-1;
    while(l<r){
        if(s[l]!=s[r]) {
            ans1++;
        }
        l++;
        r--;
    }
    cout<<ans1;
    return 0;
}
