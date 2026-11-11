#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,tot,total;
string s;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    while(n--){
        int a;
        char c;
        cin>>a;
        cin>>c;
        for(int i=1;i<=a;i++){
            s=s+c;
        }
        tot+=a;
    }
    for(int i=0;i<=tot/2-1;i++){
        if(s[i]!=s[tot-1-i]){
            total++;
        }
    }
    cout<<total;
    return 0;
} 