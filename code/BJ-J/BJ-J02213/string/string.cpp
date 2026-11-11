#include<bits/stdc++.h>
using namespace std;
long long a;
char b[1000000005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    long long cnt=1;
    char l;
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>a>>l;
        for(long long j=cnt;j<=cnt+a-1;j++){
            b[j]=l;
        }
        cnt+=a;
    }
    long long cntt=cnt;
    long long ans=0;
    long long i=1;
    while(cntt>i){
        if(b[i]!=b[n]){
            ans++;
        }
        cnt--;
        i++;
    }
    cout<<ans;
    return 0;
}
