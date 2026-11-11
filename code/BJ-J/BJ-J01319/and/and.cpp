#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200010];
string s[200010];
int b[100];
bool v[200010];
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,ans=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        for(int j=30;j>=0;j--)
            if(a[i]&(1<<j)){
                s[i]=s[i]+'1';
                b[i]++;
            }
            else s[i]=s[i]+'0';
        v[i]=1;
    }
    for(int i=30;i>=0;i--){
        if(b[i]>=m) ans+=(1<<i);
        for(int j=1;j<=n;j++)
            if((a[j]&(1<<i))==0&&v[j]){
                for(int k=0;k<=30;k++)
                    if(a[j]&(1<<k)) b[k]--;
                v[j]=0;
            }
    }
    cout<<ans;
    return 0;
}
