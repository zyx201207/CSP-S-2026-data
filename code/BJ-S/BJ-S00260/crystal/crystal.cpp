#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n;
long long m,m2;
struct node{
    long long sum;
    int num=1;//这个数的最多相同值
}a[N];
bool cmp(node A,node B){
    return A.sum<B.sum;
}
int check(int x){//对于每个a[x]最多的相同值
    int anss=0;
    int i1=x-1;//虚拟下标
    while(m2>=0&&i1>=1){
        if(a[x].sum==a[i1].sum){
            i1--;
            anss++;
            continue;
        }
        if(a[x].sum-a[i1].sum>m2){
            break;
        }else if(a[x].sum-a[i1].sum<=m2){
            m2-=(a[x].sum-a[i1].sum);
            i1--;
            anss++;
        }
    }
    return anss;
}
bool flag1=0;
int ans=0;
long long cha=1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d",&n);
    scanf("%lld",&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i].sum);
        if(i>3&&a[i].sum-a[i-1].sum!=a[i-1].sum-a[i-2].sum){
            flag1=1;
        }
    }
    if(n==1){
        printf("1");
        return 0;
    }
    if(flag1){
        sort(a+1,a+n+1,cmp);
        int id=0;
        for(int i=2;i<=n;i++){
            m2=m;
            a[i].num+=check(i);
            if(a[i].num>ans){
                id=a[i].sum;
            }
            ans=max(ans,a[i].num);
        }
        printf("%d",ans);
    }else{
        cha=a[2].sum-a[1].sum;
        int ans=0;
        for(int i=1;i<=n;i++){
            if(i*cha>m){
                ans=i;
                break;
            }else{
                m-=i*cha;
            }
        }
        printf("%d",ans);
    }
    return 0;
}
