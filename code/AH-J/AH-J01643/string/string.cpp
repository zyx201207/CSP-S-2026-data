#include<bits/stdc++.h>
using namespace std;
long long n,biaoji=0;
long long a[200005],sum=0;
char b[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>a[i]>>b[i];
        sum+=a[i];
    }
    long long lsum=0;
    for(long long i=1;i<=n;i++){
        lsum+=a[i];
        if(lsum>=sum){
            a[i]-=(lsum-sum);
            biaoji=i;
            break;
        }
    }
    long long dl=1,dr=n,cntt=0;
    while(dl!=biaoji){
        if(a[dl]>a[dr]){
                if(b[dr]!=b[dl]){
                    cntt+=a[dr];
                }
            dr--;
            a[dl]-=a[dr];
        }else if(a[dl]<a[dr]){
            if(b[dr]!=b[dl]){
                    cntt+=a[dl];
                }
            dl++;
            a[dr]-=a[dl];
        }else{
            if(b[dr]!=b[dl]){
                    cntt+=a[dr];
                }
            dl++;
            dr--;
        }
    }
    cout<<cntt;
    return 0;
}




































//CCRHFBEHHDFHUWEHBUSHUUFVEDAHOEGYASOIXIEDHrn8EVFUHOSAFFVBAUIR

