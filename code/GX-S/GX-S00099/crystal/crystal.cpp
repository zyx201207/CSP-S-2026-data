#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m,l,African,sum=0;
    cin>>n>>m;
    long long a[n],b[n];
    for(long long i=0;i<n;i++){
        cin>>a[i];
    }
    long long c=n;
    while(c!=1){
        for(long long i=0;i<c;i++){
            if(a[i]>a[i+1]){
                l=a[i];
                a[i]=a[i+1];
                a[i+1]=l;
            }
        }
        c--;
    }
    if(n%2!=0){
        African=a[(n-1)/2];
    }
    else{
        African=a[max(n/2,n/2+1)];
    }
    for(long long i=0;i<n;i++){
        if(a[i]=African){
            sum++;
            break;
        }
        sum++;
    }
    cout<<sum+2;
    return 0;
}
