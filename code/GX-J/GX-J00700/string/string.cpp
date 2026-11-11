#include <bits/stdc++.h>
using namespace std;

string s;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,a,t=0,ans=0,t1;
    char c;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a >> c;
        for(int j=1;j<=a;j++){
            s[t]=c;
            t++;
        }
    }
    if(t%2==0){
        t1=t/2;
        for(int i=1;i<=t/2;i++){
            if(s[i]!=s[t1]) ans++;
            t1-=1;
        }
    }
    else{
        t1=(t-1)/2;
        for(int i=1;i<=(t-1)/2;i++){
            if(s[i]!=s[t1]) ans++;
            t1--;
        }
    }
    cout << ans;

    return 0;
}
