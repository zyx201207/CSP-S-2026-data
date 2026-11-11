#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,a,ans=0,cnt=0;
    char b,c[8000005];
    cin>>n;
    for(long long i=0;i<n;i++){
        cin>>a;
        cin>>b;
        for(long long j=ans;j<ans+a;j++){
            c[j]=b;
        }
        ans+=a;
    }
    for(long long i=0;i<(ans+1)/2;i++){
        if(c[i]!=c[ans-i-1]){
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
