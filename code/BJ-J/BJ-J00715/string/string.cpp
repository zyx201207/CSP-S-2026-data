#include<cstdio>
int main(){
    int n,a[200002],i;
    long long ans;
    char c[200002];
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d %c",&a[i],&c[i]);
    }
    for(int j=1;a[j];j++){
        if(c[j]!=c[i-j+1]){
            if(a[j]<a[i-j+1]){
                ans+=a[j];
                a[i-j+1]-=a[j];
                i++;
            }else if(a[j]>a[i-j+1]){
                ans+=a[i-j+1];
                a[j]-=a[i-j+1];
                a[i-j+1]=0;
                j--;
                i--;
            }else{
                ans+=a[j];
                a[j]=0;
                a[i-j+1]=0;
            }
        }else{
            if(a[j]<a[i-j+1]){
                a[i-j+1]-=a[j];
                i++;
            }else if(a[j]>a[i-j+1]){
                a[j]-=a[i-j+1];
                j--;
                i--;
            }
        }
    }
    printf("%lld",ans);
    return 0;
}
//szhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjzszhhjz
