#include<bits/stdc++.h>
using namespace std;
int main ()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long  n,h=0;
    cin>>n;
    string s;
    for(long long i=1;i<=n;i++){
        long long j;
        char a;
        cin>>j>>a;
        for(long long l=1;l<=j;l++){
            s[h]=a;
            h++;
        }
    }
    long long l=h-1;
    h=0;

    for(long long x=0;x<=l/2+1;x++){

        if(s[x]!=s[l-x]){
            s[l-x]=s[0];
            h++;
        }
    }
    cout<<h;
    return 0;
}
