#include<bits/stdc++.h>
using namespace std;
long long n,a[200000],f=1,x;
char c[200000];
short s[999999999];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long  i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        for(long long j=f;j<f+a[i];j++){
            s[j]=c[i]+1-'a';
        }
        f+=a[i];
    }
    f--;
    for(long long i=1;i<=f/2;i++){
        if(s[i]!=s[f-i+1]){
            x++;
        }
    }
    cout<<x;
    return 0;
}
