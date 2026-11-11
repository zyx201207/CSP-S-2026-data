#include<bits/stdc++.h>
using namespace std;
long long n,m,l,c;
string s;
char a;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>m>>a;
        l += m;
        for(int j=0;j<m;j++)
            s += a;
    }
    n = l/2;
    for(int i=0;i<n;i++){
        if(s[i]!=s[l-i-1])
            c++;
    }
    cout<<c;
    return 0;
}
