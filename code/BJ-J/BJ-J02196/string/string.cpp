#include<bits/stdc++.h>
using namespace std;

int n;
long long a[200050];
char b[200050];

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    long long sum=0;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
        sum+=a[i];
    }
    long long num=0;
    long long l=1,r=sum;
    long long p=1,q=n;
    while(l<=r){
        long long x=min(a[p],a[q]);
        if(b[p]!=b[q]){
            num+=x;
        }
        l+=x;
        r-=x;
        a[p]-=x;
        a[q]-=x;
        if(a[p]!=0){
            q--;
            continue;
        }
        if(a[q]!=0){
            p++;
            continue;
        }
        if(a[q]==a[p]){
            p++;
            q--;
            continue;
        }
    }
    cout<<num;
    return 0;
}
