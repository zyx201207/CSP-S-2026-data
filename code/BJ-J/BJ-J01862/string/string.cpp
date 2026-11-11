#include<bits/stdc++.h>
using namespace std;
long long n,a,l,ans,mid;
char c,st[100000005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%lld",&n);//cout<<n;
    for(int i=1;i<=n;i++){
        scanf("%lld%s",&a,&c);//cout<<a<<" "<<c<<" ";
        for(int j=l+1;j<=l+a;j++){
            st[j]=c;
        }
        l+=a;//cout<<l<<" ";

    }
    mid=l/2;
    for(int i=1;i<=mid;i++){
        if(st[i]!=st[l-i+1])ans++;
    }

    printf("%lld",ans);

    return 0;
}