#include <bits/stdc++.h>
using namespace std;
char a[200000005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    long long sum=0;
    for(int i=1;i<=n;i++){
        long long t;
        cin>>t;
        char ch;
        cin>>ch;
        for(int j=sum+1;j<=sum+t;j++){
            a[j]=ch;
        }
        sum+=t;
    }
    long long ans=0;
    for(int i=1;i<=sum/2;i++){
        if(a[i]!=a[sum-i+1]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
