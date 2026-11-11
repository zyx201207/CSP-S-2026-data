#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%lld %lld",&n,&m);
    for(int i=1;i<=n;i++) scanf("%lld ",&a[i]);
    for(int i=1;i<=n;i++){
        long long card[500005]={0},sizee=1;
        for(int j=i;j<=n;j++){
            long long num=a[j],id=0;
            bool f=0;
            for(int k=1;k<=sizee;k++)
                if(card[k]==num) f=1,id=k+1;
            if(f==0) card[sizee++]=num;
            else
                for(int k=id;k<=sizee;k++) card[k]=0;
        }
        for(int i=1;i<=sizee;i++) ans[card[i]]++;
    }
    for(int i=1;i<=m;i++) printf("%lld ",ans[i]);
    return 0;
}
