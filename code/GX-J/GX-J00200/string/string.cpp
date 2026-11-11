#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen('string.in','r',stdin);
    freopen('string.out','w',stdout);
    long long m,n[10005];
    string s;
    cin>>m;
    for(long long i=1;i<=m;i++){
        cin>>n[i];
        cin>>s[i];
        for(long long l=1;l<=n[i];l++){
            cout<<s[i];
        }

    }

    return 0;
}




