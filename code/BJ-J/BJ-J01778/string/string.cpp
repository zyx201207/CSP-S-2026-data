#include<bits/stdc++.h>
using namespace std;
char c;
string s;
int n,m=0,a,t=0,da=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a>>c;
        m+=a;
        t+=a;
        for(int j=t;j<=t+a;j++){
            s[j]=c;
        }
    }
    for(int i=0;i<m;i++){
        if(s[i]!=s[m-i-1]) da++;
    }
    cout<<da;
    return 0;
}
