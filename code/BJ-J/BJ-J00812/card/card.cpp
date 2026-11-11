#include<bits/stdc++.h>
using namespace std;
int a[500005],ans[300005],s[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n;++i){
        scanf("%d",&a[i]);
    }
    for(int i = 1;i <= n;++i){
        int l=0;
        for(int j = i;j <= n;++j){
            ++l;
            s[l]=a[j];
            for(int k = 1;k < l;++k){
                if(s[k]==a[j]){l=k;}
            }
        }
        for(int j = 1;j <= l;++j){
            ++ans[s[j]];
        }
    }
    for(int i = 1;i <= m;++i){
        printf("%d ",ans[i]);
    }
    return 0;
}
