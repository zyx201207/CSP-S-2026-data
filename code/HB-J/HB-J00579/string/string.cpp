#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=220000;
LL n,ans;
LL a[N],l,r,c_1,c_2;
//bool p_1,p_2;
char c[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        cin>>c[i];
    }
    l=0,r=n+1;
    while(l<r){
        if(c_1==0){
            l++;
            c_1=a[l];
        }
        if(c_2==0){
            r--;
            c_2=a[r];
        }
        if(l>=r) break;
        //printf("%d %d %d %d\n",l,c_1,r,c_2);
        LL cmp=min(c_1,c_2);
        if(c[l]!=c[r]){
            ans+=cmp;
        }
        c_1-=cmp;
        c_2-=cmp;
    }
    printf("%lld",ans);
    return 0;
}


