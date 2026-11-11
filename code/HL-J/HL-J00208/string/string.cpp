#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    long long a[n+10]={0},s=1,sum=0,s1=0;
    char c[n+10]={0},z[n+10]={0};
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cin>>c[i];
        for(long long j=1;j<=a[i];j++){
            z[s-1+j]=c[i];
        }
        s+=a[i];
        s1+=a[i];
    }
    for(int i=1;i<=s1/2;i++){
        if(z[i]!=z[n-i+1]) sum++;
    }
    cout<<sum;
    return 0;
}
