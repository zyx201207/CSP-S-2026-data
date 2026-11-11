#include<bits/stdc++.h>
using namespace std;
long long n,m,a[511111],s[511111];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        //cin>>a[i];
        a[i] = i;
    }
    //cout<<1;
    sort(a+1,a+1+n);
    for(int i = 1;i<n;i++){
        s[i] = a[i+1]-a[i];

    }
    long long k = m;
    long long zuo = 1,maxn = 1,ans = 1;
    for(int i = 1;i<=n;i++){
        maxn = max(maxn,ans);
        if(m>=ans*s[i]) {
            m-=ans*s[i];
            ans++;

        }else{
            while(ans>1 && m<ans*s[i]){
                m+=(ans-1)*s[zuo];
                zuo++;
                ans--;
            }
            //m+=(ans-1)*s[zuo];
            if(m<ans*s[i]) {
                zuo = i;
                m = k;
                continue;
            }
            m-=ans*s[i];
            ans++;
        }
    }
    cout<<maxn;

    return 0;

}
