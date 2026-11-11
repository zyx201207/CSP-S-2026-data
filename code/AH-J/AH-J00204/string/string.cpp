#include<bits/stdc++.h>
using namespace std;
char l[99999];
int main(){
    freopen("string.in","r", stdin);
    freopen("string.out","w",stdout);
    long long n,lo = 0;
    cin>>n;
    cin>>l[0];
    for(long long i = 0;i<n;i++){
        long long  o;
        cin>>o>>l[i];
        lo+=o;
        for(long long j = 1;j<o;j++){
            l[i+j]=l[i];
        }
    }
    long long ans=0;
    for(long long i = 0, j = lo-1;i<lo-1, j>0;i++,j--){
        if(l[i]!=l[j]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
