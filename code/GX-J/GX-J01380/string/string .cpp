#include<bits/stdc++.h>
using namespace std;
long long n;
string a;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        long long k;
        char c;
        cin>>k>>c;
        for(long long j=1;j<=k;j++) a+=c;
    }
    long long sum=0,len=a.size()-1,lenn,km;
    if(len%2){
        lenn=len/2+1;
        km=1;
    }else{
        lenn=len/2+1;
        km=2;
    }
    for(long long i=lenn;i<=len;i++){
        if(a[i]!=a[i-km]) sum++;
        km+=2;
    }
    cout<<sum;
    return 0;
}
