#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct node{
    int x;
    char c;
}a[200010];

int main (){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    scanf("%d",&n);
    ll sum=0;
    for(int i=1;i<=n;i++){
        scanf("%d %c",&a[i].x,&a[i].c);
        sum+=a[i].x;
    }
    ll num=0,k=1;
    ll i1=0,j1=0,i2=0,j2=0;
//    printf("sum>>1=%lld (sum+3)>>1=%lld\n",sum>>1,(sum+3)>>1);
//    printf("start searching for i1&i2\n");
    while(1){
        while(num+a[k].x<=sum>>1){
            num+=a[k].x;
            k++;
//            printf("add num=%lld k=%lld\n",num,k);
        }
        if(num==sum>>1){
            i1=a[k-1].x;
            i2=k-1;
//            printf("1found k=%lld i1=%lld i2=%lld\n",k,i1,i2);
            break;
        }
        if(num+a[k].x>sum>>1){
            i1=(sum>>1)-num;
            i2=k;
//            printf("2found k=%lld i1=%lld i2=%lld\n",k,i1,i2);
            break;
        }
    }
//    printf("start searching for j1&j2\n");
    while(num<=(sum+3)>>1){
        while(num+a[k].x<=(sum+3)>>1){
            num+=a[k].x;
            k++;
//            printf("add num=%lld k=%lld\n",num,k);
        }
        if(num==(sum+3)>>1){
            j1=1;
            j2=k-1;
//            printf("1found k=%lld j1=%lld j2=%lld\n",k,j1,j2);
            break;
        }
        if(num+a[k].x>(sum+3)>>1){
            j1=a[k].x-(((sum+3)>>1)-num)+1;
            j2=k;
//            printf("2found k=%lld j1=%lld j2=%lld num=%lld\n",k,j1,j2,num);
            break;
        }
    }
//    printf("i1=%lld i2=%lld j1=%lld j2=%lld\n",i1,i2,j1,j2);
//    printf("sum=%lld\n",sum);

    ll i=sum>>1,j=(sum+3)>>1;
    ll ans=0;
//    printf("i=%lld j=%lld\n",i,j);
    while(i1>0||i2>0){
        if(i1==j1){
//            printf("change 1\n");
            i-=i1;
            j+=j1;
            if(a[i2].c!=a[j2].c) ans+=i1;
            i1=a[--i2].x,j1=a[++j2].x;
        }
        if(i1>j1){
//            printf("change 2\n");
            i1-=j1,i-=j1;
            if(a[i2].c!=a[j2].c) ans+=j1;
            j1=a[++j2].x;
        }
        if(j1>i1){
//            printf("change3\n");
            j1-=i1,j+=i1;
            if(a[i2].c!=a[j2].c) ans+=i1;
            i1=a[--i2].x;
        }
        if(j2<3000){
//        printf("ans=%lld\n",ans);
//        printf("i=%lld j=%lld i1=%lld i2=%lld j1=%lld j2=%lld\n",i,j,i1,i2,j1,j2);   
        }
        
    }
    printf("%lld",ans);
    return 0;
}
/*
25307 25309
sum:50615
*/