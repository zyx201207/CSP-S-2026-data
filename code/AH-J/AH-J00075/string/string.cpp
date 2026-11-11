#include<bits/stdc++.h>
using namespace std;
int t,a,ans;
char c;
string s;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>a>>c;
        for(int i=0;i<a;i++) s+=c;
    }
    string q=s;
    reverse(q.begin(),q.end());
    if(q==s){cout<<0;return 0;}
    int l=0;
    if(s.size()%2==0){
        l=s.size()/2;
        for(int i=l;i<s.size();i++){
            if(s[i]!=q[i]) ans++;
        }
    }else{
        l=s.size()/2+1;
        for(int i=l;i<s.size();i++){
            if(s[i]!=q[i]) ans++;
        }
    }
    cout<<ans;
    return 0;
}
