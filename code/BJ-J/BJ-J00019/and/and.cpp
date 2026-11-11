#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int a[200000],m;
int solve(int l,int r,int f){
    if(r-l+1<m||f==0)
        return 0;
    int num=(1<<f)-1,num2=1<<f-1,sum=0;
    for(int i=l;i<=r;i++){
        a[i]&=num;
        if(a[i]>=num2)
            sum++;
    }
    if(sum>=m){
        int x=l;
        while(a[x]<num2)
            x++;
        return max(num2,1)+solve(x,r,f-1);
    }
    int num3=num2-1;
    for(int i=l;i<=r;i++)
        a[i]&=num3;
    sort(a+l,a+r+1);
    return solve(l,r,f-1);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    sort(a,a+n);
    if(a[n-1]==1){
        int sum=0;
        for(int i=0;i<n;i++)
            if(a[i])
                sum++;
        if(sum>=m)
            printf("1");
        else
            printf("0");
        return 0;
    }
    int x=ceil(log2(a[n-1]))+1e-6;
    printf("%d",solve(0,n-1,x));
    return 0;
}