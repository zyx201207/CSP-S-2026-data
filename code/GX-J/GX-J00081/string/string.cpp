#include <bits/stdc++.h>
using namespace std;

const int maxn=2*1e5+5;
struct node{
    int num;
    char c;
}a[maxn];
int ans=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    string s;
    s+='*';
    for(int i=1;i<=n;i++){
        cin>>a[i].num>>a[i].c;
        for(int j=1;j<=a[i].num;j++) s+=a[i].c;
    }
    string temp=s;
    reverse(temp.begin(),temp.end());
    if(temp==s){
        cout<<'0';
        return 0;
    }
    temp=s;
    int len=s.size()-1;
    for(int i=1;i<=(len+1)/2;i++){
        if(s[i]!=s[len-i+1]) s[len-i+1]=s[i];
    }
    for(int i=1;i<=len;i++){
        if(temp[i]!=s[i]) ans++;
    }
    cout<<ans;
    return 0;
}
