#include<cstdio>//<-include less head file(just one! :) )
using namespace std;
long long n,m,l,r,mid,sum,tmp,m1,cnt,ans,a[500005];//a lot of variables:(
bool c(long long x){
    sum=cnt=0;m1=m;
    for(int i=0;i<n;i++){
        tmp=x-a[i];
        if(tmp>=0){
            sum+=tmp;
            if(m1>=tmp)m1-=tmp,cnt++;
        }
    }
    return sum>m;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);//<-use this to save time
    for(int i=0;i<n;r=(r>a[i]?r:a[i]),l=(l>a[i]?a[i]:l),i++)scanf("%lld",&a[i]);
    while(l<r){//Binary answer
        mid=((l+r)>>1);
        if(c(mid)){
            r=mid;
        }else{
            ans=(ans>cnt?ans:cnt);
            l=mid+1;
        }
        //printf("l=%lld r=%lld m=%lld cnt=%lld sum=%lld\n",l,r,mid,cnt,sum);
    }
    c((l+r)>>1);
    ans=(ans>cnt?ans:cnt);
    printf("%lld",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
//maybe I'm right
//I pass first,second and third test point,but crystal 4 is error,why?
//crystal 4.in(a piece of):500000 19768503
//61 64 18 17 -54 -41 47 83 24 89 -67 -6 -24 -69 26 -41 77 -44 5 21 54......
//that's so large...
//ans:315275
//this code make mistakes when it face a little big test point I don't know why
