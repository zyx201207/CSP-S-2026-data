#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,m;
int lis[N];
int len,lose;
bool cmp(int a,int b){
    int c=a,d=b;
    return (c&lose)<(d&lose);
}
int ans;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    int ma=0;
    for(int i=1;i<=n;i++){
        scanf("%d",&lis[i]);
        ma=max(ma,lis[i]);
    }
    int l=0;
    for(int i=ma;i>0;i>>=1){
        l++;
    }
    l--;
    ans=lose=(1<<l)-1+(1<<l);
    //printf("%d\n",ans);
    len=1;
    for(int i=l+1;i>=1;i--){
        sort(lis+len,lis+1+n,cmp);
        //for(int j=1;j<=n;j++){
        //   printf("%d ",lis[j]);
        //}
        //printf("\n");
        int ll=len,rr=n;
        for(;;){
            if(ll>=rr) break;
            int mid=(ll+rr)/2;
            if((lis[mid]&(1<<(i-1)))==(1<<(i-1))){
                rr=mid;
            }
            else{
                ll=mid+1;
            }
            //printf("!!%d %d %d\n",ll,rr,(1<<(i-1)));
        }
        int l1=ll;
        if(n-l1+1>=m){
            len=l1;
        }
        else{
            ans-=(1<<(i-1));
        }
        lose-=(1<<(i-1));
        //printf("%d %d\n",len,l1);
    }
    printf("%d",ans);
    return 0;
}
