#include<iostream>

using namespace std;
using LL =long long;
const LL N = 2e5+5;
LL n,a[N],ans;
char c[N];
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%lld",&n);
    for(LL i=1;i<=n;i++){
        scanf("%lld",a+i);
        cin>>c[i];
    }


    for(LL i=1;i<=n;i++)
        for(LL j=1;j<=a[i];j++)
            s+=c[i];

    LL l=0,r=s.size()-1;
    while(l<r){
        if(s[l]!=s[r])ans++;
        l++,r--;
    }

    /*
    LL l=1,r=n;
    while(l<r){
        if(a[l]==a[r]){
            if(c[l]!=c[r])
                ans+=a[l];
            l++,r--;
        }else{
            if(a[l]>a[r]){
                if(c[l]!=c[r]){
                    ans+=a[r];
                    a[l]-=a[r];
                }
                r--;
            }else {
                if(c[l]!=c[r]){
                    ans+=a[l];
                    a[r]-=a[l];
                }
                l++;
            }
        }
    }*/
    cout<<ans;
    return 0;
}
