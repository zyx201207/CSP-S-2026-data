#include <bits/stdc++.h>
using namespace std;
int n;
char shuzi[200010];
long long a[200010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>shuzi[i];
    }
    int l=1,r=n;
    long long ans=0,shengyul=a[1],shengyur=a[r];
    while(l<r){
        if(shuzi[l]==shuzi[r]){
            if(shengyul>shengyur){
                shengyul-=shengyur;
                r--,shengyur=a[r];
            }else if(shengyul<shengyur){
                shengyur-=shengyul;
                l++,shengyul=a[l];
            }else{
                l++,r--;
                shengyul=a[l],shengyur=a[r];
            }
        }else{
            if(shengyul>shengyur){
                ans+=shengyur;
                shengyul-=shengyur;
                r--,shengyur=a[r];
            }else if(shengyul<shengyur){
                ans+=shengyul;
                shengyur-=shengyul;
                l++,shengyul=a[l];
            }else{
                ans+=shengyul;
                l++,r--;
                shengyul=a[l],shengyur=a[r];
            }
        }
    }
    cout<<ans;
    return 0;
}
