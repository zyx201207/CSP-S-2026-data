#include<bits/stdc++.h>
using namespace std;
long long n,cnt=1;
int ans;
int a[200010];
char c[2146671178],x;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>x;
        for(int j=1;j<=a[i];j++){
            c[cnt]=x;
            cnt++;
        }
    }
    cnt-=1;
    for(int i=1;i<=(cnt+1)/2;i++){
        if(c[i]!=c[cnt-i+1]){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
