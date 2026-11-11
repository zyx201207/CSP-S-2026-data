#include<bits/stdc++.h>
using namespace std;
string s;
long long n,a[210000],num=0,p;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++){
        string c;
        cin>>a[i]>>c;
        p+=a[i];
        for(long long j=1;j<=a[i];j++){
            s=s+c;
        }
    }
    p-=n;
    for(long long i=0;i<=p/2;i++){
        if(s[i]!=s[p-i])num++;
    }
    cout<<num;
    return 0;
}
