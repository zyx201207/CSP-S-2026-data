#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    long long a[n];
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    long long sum=n/2*(n-1);
    long long mx=INT_MIN;
    long long a1[n];
    int num=0;
    int num1=1;
    for(int i=1;i<=sum;i++){
        num++;
        a1[i]=a[num] and a[num+num1];
        mx=max(mx,a1[i]);
        if((num+num1)>=n){
            num1++;
            num=0;
        }
    }
    if(m=2){
        cout<<mx;
        return 0;
    }
    if(m=1){
        mx=INT_MIN;
        for(int i=1;i<=n;i++){
            mx=max(mx,a[i])
        }
    cout<<mx;
    }
    return 0;
}
