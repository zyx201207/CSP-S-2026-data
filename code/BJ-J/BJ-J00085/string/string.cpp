#include<bits/stdc++.h>
using namespace std;
char long long c[200005],s[200005];
int long long n,a[200005],x=0,cnt=0;
int main(){
    cin>>n;
    for(int long long i=1;i<=n;i++){
        cin>>a[i];
        cin>>c[i];
        for(int long long j=1;j<=a[i];j++){
            x++;
            s[x]=c[i];
        }
    }
    for(int long long i=1;i<=x/2;i++){
        if(s[i]!=s[x-i+1]){
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}