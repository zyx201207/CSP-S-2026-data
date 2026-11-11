#include<bits/stdc++.h>
using namespace std;
char c[2000010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n;
    cin>>n;
    long long cnt=1;
    for(long long i=1;i<=n;i++){
        long long x,j;
        char t;
        cin>>x>>t;
        for(j=cnt;j<=cnt+x-1;j++){
            c[j]=t;
        }
        cnt=j;
    }
    cnt--;
    long long ans=0;
    for(long long i=1;i<=cnt/2;i++){
        if(c[i]!=c[cnt-i+1]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
