#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,q,c=0,sum=0;
    char x;
    string a[200007],s[200007];
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>q>>x;
        for(long long j=1;j<=q;j++){
            a[c]=x;
            c++;
        }
    }
    if(c%2==0){
        sum==c/2;
    }
    if(c%2!=0){
        sum==(c-1)/2;
    }
    cout<<sum;
    return 0;
}
