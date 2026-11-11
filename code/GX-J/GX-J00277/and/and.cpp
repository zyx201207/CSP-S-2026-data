#include<bits/stdc++.h>
using namespace std;
long long yu(int a,int b){
    long long a1[10007],b1[10007],i=1,j=1,sum,s=1;
    while(a!=0){
        a1[i]=a%2;
        a/=2;
        i++;
    }
    while(b!=0){
        b1[j]=b%2;
        b/=2;
        j++;
    }
    for(long long m=1;m<=max(i,j);m++){
        if(a1[m]==b1[m]){
            sum+=s;
        }
        s*=2;
    }
    return sum;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m,af;
    cin>>n>>m;
    long long a[n],dp[m+1];
    for(long long i=0;i<n;i++){
        cin>>a[i];
    }
    for(long long j=m;j>0;j--){
        int max=-1;
        for(long long f=0;f<n;f++){
                if(a[f]>max){
                    max=a[f];
                }
            dp[j]=max;
    }
    af=dp[1];
    for(long long i=2;i>=m;i++){
        af=yu(af,dp[i]);
    }
    cout<<af;
    return 0;
}
}
