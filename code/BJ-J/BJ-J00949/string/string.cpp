#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
struct node{
    ll x;
    char ch;
}a[200100];
string s;
ll ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].x>>a[i].ch;
        for(int j=1;j<=a[i].x;j++){
            s+=a[i].ch;
        }
    }
    for(int i=0,j=s.size()-1;i<s.size()/2;i++,j--){
        if(s[i]!=s[j])ans++;
    }
    cout<<ans;
    return 0;
}