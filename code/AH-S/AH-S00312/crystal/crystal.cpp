#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=-1,a[500005],te[500005];
int main(void){
    //freopen("crystal.in","r",stdin);
    //freopen("crystal.out","w",stdout);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    for(int i=1;i<n;i++)
        te[i]=te[i-1]+(a[i+1]-a[i])*i;
    for(int i=1;i<n;i++){
        long long l=i+1,r=n;
        while(l<=r){
            long long mid=(l+r)/2;
            long long v=te[mid]-te[i-1]-(i-1)*(a[mid+1]-a[i]);
            if(v<=m)
                l=mid+1;
            else r=mid-1;
        }
        ans=max(ans,l-i+1);
    }
    printf("%lld",ans);
    return 0;
}
//hello
//I wrote something in my CSP-J's program,you can try to find them(AH-J00540).
//I don't want to write them again.
//Code by __LCD(Luogu uid:1057768)

//118 minutes:address T1 (I want to cry.55555)
//126 minutes:my desk mate is noisy too.I wonder why I can't have a good EX this time.
//148 minutes:I can't deal with them.maybe i should return to study whk.
//211 minutes:I do nothing but play chess.It's funner than doing problems i can't solve.

//Expect:
//T1:0~100    points
//T2:0        points
//T3:0        points
//T4:0        points
//Total:0~100 points

//hope i can get 3= price,it's better to get 2= price.
