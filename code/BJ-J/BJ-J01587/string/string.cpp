#include<bits/stdc++.h>
using namespace std;
long long n,l,sum=0,z=0;
string c,a="";
int main(){
    freopen("string.in",'r',stdin);
    freopen("string.out",'w',stdout);
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>l>>c;
        for(long long j=1;j<=l;j++){
            a+=c;
            z++;
        }
    }
    for(long long i=0;i<z/2;i++){
        if(a[i]!=a[z-i-1]){
            sum++;
        }
    }
    cout<<sum;
    return 0;
}
