#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
long long ans1,ans2,slen;
string s,t,c;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c;
        for(int j=1;j<=a[i];j++){
            s=s+c;
        }
    }
    slen=s.size();
    for(int i=0;i<slen;i++){
        t=t+s[slen-i-1];
    }
    for(int i=0;i<slen/2;i++){
        if(s[i]!=t[i]){
            ans1++;
        }
    }
    for(int i=slen/2;i<slen;i++){
        if(s[i]!=t[i]){
            ans2++;
        }
    }
    cout<<min(ans1,ans2);
    return 0;
}