#include<bits/stdc++.h>
using namespace std;
int a[200005];
char c[200005];
char cc[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    cin>>n;
    long long ans=0;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=a[i];j++){
            cc[j+cnt]=c[i];
        }
        cnt+=a[i];
    }
    for(int i=1,j=cnt;i<=j;i++,j--){
        if(cc[i]!=cc[j]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
