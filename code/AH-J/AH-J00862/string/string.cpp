#include <bits/stdc++.h>
using namespace std;
long long n,a[200000009],sum=0,b=0;
char c[200000009];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
         cin>>a[i]>>c[i];
         b+=a[i];
    }
    long long k=1,s=b;
    for(int i=0;i<=b-1;i++){
        if(c[k]!=c[s]){
            c[s]=c[k];
            sum++;
        }
        k++,s--;
        if(k==s) break;
    }
    cout<<sum;
    return 0;
}
