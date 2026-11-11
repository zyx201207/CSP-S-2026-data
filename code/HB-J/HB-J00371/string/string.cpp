#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[200010],res[200010],pre[200010],suf[200010];
char c[200010];
int m,b[1000010],ans;
char s[1000010];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        res[i]=a[i];
        scanf(" %c",&c[i]);
        // printf("%c\n",c[i]);
    }
    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1]+a[i];
    }
    for(int i=n;i>=1;i--){
        suf[i]=suf[i+1]+a[i];
    }
    int pl=1,pr=n;
    while(pl<=n&&pr>=1){
        int lsiz=pre[pl],rsiz=suf[pr];
        if(lsiz<rsiz){
            // printf("%d %d 1\n",pl,pr);
            b[++m]=res[pl];
            s[m]=c[pl];
            // printf("{%lld %c}\n",res[1],s[m]);
            pl++;
        }else{
            // printf("%d %d 2\n",pl,pr);
            //lsiz-res=rsiz
            b[++m]=res[pl]-(lsiz-rsiz);
            s[m]=c[pl];
            res[pl]=lsiz-rsiz;
            pr--;
        }
    }
    // for(int i=1;i<=m;i++){
    //     printf("%lld %c\n",b[i],s[i]);
    // }
    // printf("\n");
    for(int i=1;i<=m;i++){
        if(s[i]!=s[m-i+1]){
            ans+=b[i];
        }
    }
    printf("%lld\n",ans/2ll);
    return 0;
}
/*
g++ string.cpp -o exe -Wall -O2
./exe
diff string.out string.ans

*/

/*
Qu(4) Mai(3)<Hao(3) Gu(1) Niang(0) Guang(1) Mang(2) Wan(4) Zhang(4)>
*/

/*
You take me to hell,
form heven I feel.
You put on a fire of ????
You make me believe, you love me indeed.
The truth is you don't know what love is.
*/

/*
#include<bits/stdc++.h>
using namespace std;
struct Seg{
    struct Node{
        int mx,mn,sum,add,cov;
    }tr[400010];
    void add(int u,int l,int r,int qk){
        tr[u].add+=qk;
        tr[u].sum+=qk*(r-l+1);
        tr[u].mn+=qk;
        tr[u].mx+=qk;
    }
    void cover(int u,int l,int r,int qk){
        tr[u].add=0;
        tr[u].cov=qk;
        tr[u].mn=tr[u].mx=qk;
        tr[u].sum=qk*(r-l+1);
    }
    void pushdown(int u,int l,int r){
        int mid=(l+r)>>1;
        if(tr[u].cov){
            cover(u<<1,l,mid,tr[u].cov);
            cover(u<<1|1,mid+1,r,tr[u].cov);
            tr[u].cov=0;
        }
        if(tr[u].add){
            add(u<<1,l,mid,tr[u].add);
            add(u<<1|1,mid+1,r,tr[u].add);
            tr[u].add=0;
        }
    }
    void pushup(int u){
        tr[u].mx=max(tr[u<<1].mx,tr[u<<1|1].mx);
        tr[u].mn=min(tr[u<<1].mn,tr[u<<1|1].mn);
        tr[u].sum=tr[u<<1].sum+tr[u<<1|1].sum;
    }
    void build(int u,int l,int r){
        tr[u].add=tr[u].cov=0;
        if(l==r){
            tr[u].mn=1000000;
            tr[u].mx=-1000000;
            tr[u].sum=0;
            return;
        }
        int mid=(l+r)>>1;
        build(u<<1,l,mid);
        build(u<<1|1,mid+1,r);
        pushup(u);
    }
    void updateAdd(int u,int l,int r,int ql,int qr,int qk){
        if(r<=ql||qr<=l){
            return;
        }
        if(ql<=l&&r<=qr){
            add(u,l,r,qk);
            return;
        }
        pushdown(u,l,r);
        int mid=(l+r)>>1;
        updateAdd(u<<1,l,mid,ql,qr,qk);
        updateAdd(u<<1|1,mid+1,r,ql,qr,qk);
        pushup(u);
    }
    void updateCov(int u,int l,int r,int ql,int qr,int qk){
        if(r<=ql||qr<=l){
            return;
        }
        if(ql<=l&&r<=qr){
            cover(u,l,r,qk);
            return;
        }
        pushdown(u,l,r);
        int mid=(l+r)>>1;
        updateCov(u<<1,l,mid,ql,qr,qk);
        updateCov(u<<1|1,mid+1,r,ql,qr,qk);
        pushup(u);
    }
    int querySum(int u,int l,int r,int ql,int qr){
        if(r<=ql||qr<=l){
            return 0;
        }
        if(ql<=l&&r<=qr){
            return tr[u].sum;
        }
        pushdown(u,l,r);
        int mid=(l+r)>>1;
        return querySum(u<<1,l,mid,ql,qr)+querySum(u<<1|1,mid+1,r,ql,qr);
    }
    int queryMax(int u,int l,int r,int ql,int qr){
        if(r<=ql||qr<=l){
            return -1000000;
        }
        if(ql<=l&&r<=qr){
            return tr[u].mx;
        }
        pushdown(u,l,r);
        int mid=(l+r)>>1;
        return max(queryMax(u<<1,l,mid,ql,qr),queryMax(u<<1|1,mid+1,r,ql,qr));
    }
    int queryMin(int u,int l,int r,int ql,int qr){
        if(r<=ql||qr<=l){
            return 1000000;
        }
        if(ql<=l&&r<=qr){
            return tr[u].mn;
        }
        pushdown(u,l,r);
        int mid=(l+r)>>1;
        return min(queryMin(u<<1,l,mid,ql,qr),queryMin(u<<1|1,mid+1,r,ql,qr));
    }
}seg;
signed main(){
    int n=10;
    seg.build(1,1,n);
    // seg.updateCov(1,1,n,1,n,1);
    // seg.updateAdd(1,1,n,1,3,10);
    // seg.updateAdd(1,1,n,5,7,100000);
    seg.updateCov(1,1,n,2,2,-100);
    printf("%d\n",seg.querySum(1,1,n,2,2));
    
    return 0;
}
OUTPUT 0.WA.
If you want to help me, please send message to Luogu (User_Name: lplhzx)
*/
