#include<bits/stdc++.h>
using namespace std;
struct no{
    unsigned long long k;
    char c;
};
no a[200010];
char ch[1000005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    //去注释！！！
    unsigned long long n;
    cin>>n;
    unsigned long long cnt=1;
    for(int i=1;i<=n;i++){
        cin>>a[i].k>>a[i].c;
        for(int j=1;j<=a[i].k;j++){
            ch[cnt]=a[i].c;
            cnt++;
        }
    }
    int ans=0;
    for(int i=1;i<=cnt/2;i++){
        if(ch[i]!=ch[cnt+1-i]) {
            ans++;
        }
    }
    if(ans%2==1&&ans!=1) cout<<ans;
    else cout<<ans/2*2;
    return 0;
}

