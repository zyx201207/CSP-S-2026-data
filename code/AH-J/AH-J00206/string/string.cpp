#include <bits/stdc++.h>
using namespace std;
const long long N=2e5+5;
long long n,a[N],k,b[N],sum;
string s;
char c[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        if(c[i]==c[i-1]){a[i]+=a[i-1];a[i-1]=0;}
    }
    for(long long i=1;i<=n;i++)
        if(a[i]!=0){b[++k]=a[i];c[k]=c[i];}
    long long l=1,r=k;
    while(l<r){
        if(c[l]==c[r]){
            long long x=min(b[l],b[r]);
            b[l]-=x;
            b[r]-=x;
            if(b[l]<=0) l++;
            if(b[r]<=0) r--;
        }
        else{
            long long x=min(b[l],b[r]);
            sum+=x;
            b[l]-=x;
            b[r]-=x;
            if(b[l]<=0) l++;
            if(b[r]<=0) r--;
        }
    }
    cout<<sum;
    return 0;
}
