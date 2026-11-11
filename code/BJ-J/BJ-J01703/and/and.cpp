#include<bits/stdc++.h>
using namespace std;
#define int long
int bok[50],ans,w,cnt;
int n,m,a[200005],num;
int book[200005];//book is equaled to 0 at begin and equaled to 1 if the number don't have any value
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        w=a[i],cnt=0;
        while(w){
            if(w&1)bok[cnt]++;
            w>>=1;
            cnt++;
        }
    }
    for(int i=31;i>=0;i--){
        if(bok[i]>=m){
            int key=(1<<i);
            for(int i=1;i<=n;i++){
                if(book[i]==1)continue;
                if(a[i]<ans+key){
                    book[i]=1;
                    w=a[i],cnt=0;
                    while(w){
                        if(w&1)bok[cnt]--;
                        w>>=1;
                        cnt++;
                    }
                }
            }
            ans+=key;
        }
    }
    printf("%lld\n",ans);
    return 0;
}
