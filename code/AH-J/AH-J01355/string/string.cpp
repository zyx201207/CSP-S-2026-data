#include<bits/stdc++.h>
using namespace std;
struct t{
    long long x;char y;
}a[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;cin>>n;string s;long long c=0,sum=0;
    for(int i=0;i<n;i++){
        cin>>a[i].x>>a[i].y;
        for(long long j=c;j<a[i].x+c;j++){
            s[j]=a[i].y;
        }c+=a[i].x;
    }
    for(long long i=0;i<(c+1)/2;i++){
        if(s[i]!=s[c-i-1]) sum++;
    }cout<<sum;
    return 0;
}
