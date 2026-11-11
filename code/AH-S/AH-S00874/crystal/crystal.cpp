#include<bits/stdc++.h>
using namespace std;
const int N=1e12+5;
int n;
long long m;
typedef struct myarr{
    long long idx;
    int val;
}myarr;
myarr a[N];
bool mycmp(myarr a1,myarr a2);
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.ans","w",stdout);
    long long cur;
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d %lld",&n,&m);
    for(long long i=1;i<=n;i++){
        bool f=false;
        scanf("%lld",cur);
        a[cur].val++;
        if(!flag){
            a[cur].idx=cur;
        }
    }
    sort(a+1,a+1+n,mycmp);
    int ans=a[1].val;
    while(m>=0){
        int n=2;
        for(int i=1;i<=a[n].val&&m>0;i++){
            if(a[n].val!=a[1].val){
                int mid=a[1].val-a[n].val;
                if(mid<=m){
                    a[n].val+=mid;
                    m-=mid;
                    ans++;
                }else{
                    break;
                }
            }
        }
        n++;
    }
    printf("%d\n",ans);
    return 0;
}
bool mycmp(myarr a1,myarr a2){
    if(a1.val==a2.val){
        return a1.idx<a2.idx;
    }
    return a1.val>a2.val;
}
