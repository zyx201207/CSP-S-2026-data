//GZ-J00008
//陈申翰林
//贵阳市第三十三中学
#include<bits/stdc++.h>
using namespace std;
long long n,a[200010];
char c[200010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int tmp=0,ans=0;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
    for(int i=n;i>0;i--){
            tmp=1;
        for(int j=a[i];j>0;j--){
            tmp++;
            if(c[i]!=c[tmp])ans++;
        }
    }
    if(ans>=2)ans/=2;
    else cout<<0;
    cout<<ans;
    return 0;
}
