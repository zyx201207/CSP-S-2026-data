#include<bits/stdc++.h>
char a[100000005];
int b[200005];
char c[200005];
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int sum=0,cnt=0,ans=0;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>b[i]>>c[i];
        sum+=b[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1+cnt;j<=cnt+b[i];j++){
            a[j]=c[i];
        }
    }
    for(int i=1;i<=n/2;i++){
        if(a[i]!=a[n-i+1]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}