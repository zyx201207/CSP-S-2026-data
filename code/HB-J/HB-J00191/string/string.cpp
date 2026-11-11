#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+5;
int n,ans;
int a[MAXN],sum[MAXN];
char c[MAXN];
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        sum[n]+=a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=a[i];j++){
            s+=c[i];
        }
    }
    for(int i=0;i<sum[n]/2;i++){
        if(s[i]!=s[sum[n]-i-1]){
                ans++;
        }
    }
    cout<<ans;
    return 0;
}
