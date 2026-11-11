#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=2e5+10;
LL a[N];
char c[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    LL n,maxn=0;
    string s;
    scanf("%lld",&n);
    for(LL i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        cin>>c[i];
        maxn=max(maxn,a[i]);
    }
    LL cnt=0;
    if(maxn<=500){
        for(LL i=1;i<=n;i++){
            for(LL j=1;j<=a[i];j++) s+=c[i];
        }
        LL j=s.size()-1,i=0;
        while(i<=j){
            if(s[i]!=s[j]) cnt++;
            i++;j--;
        }
        printf("%lld",cnt);
    }else{
        LL i=1,j=n;
        while(i<j){
            if(a[i]==a[j]){
                if(c[i]!=c[j]) cnt+=a[i];
                i++;j--;
            }
            else if(a[i]>a[j]){
                if(c[i]!=c[j]){
                    cnt+=a[j];
                }
                a[i]-=a[j];
                j--;
            }else{
                if(c[i]!=c[j]){
                    cnt+=a[i];
                }
                a[j]-=a[i];
                i++;
            }
        }
        printf("%lld",cnt);
    }
    return 0;
}
