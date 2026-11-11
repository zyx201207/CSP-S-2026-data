#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    long long a[n],sum=0,j=0,x=0;
    char s[n],c[1000000];
    for(int i=0;i<n;i++){
        cin>>a[i]>>s[i];
        sum+=a[i];
        for(;j<sum;j++){
            c[j]=s[i];
        }
    }
    for(int i=0,b=sum-1;i<b;i++,b--){
        if(c[i]!=c[b])x++;
    }
    cout<<x;
    return 0;
}