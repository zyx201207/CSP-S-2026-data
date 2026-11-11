#include<cstdio>
#include<cmath>
using namespace std;
const int N=4e3;
int a[N],b[N],c[N];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,max1=0,max2=0,s=0;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%d",x);
        if(x>=max1) max1=x;
        if(x<=max1&&x>max2) max2=x;
        int j=0;
        for(j=0;max2!=0;j++){
            b[j]+=max2%2;
            max2/=2;
        }
        for(j=0;max1!=0;j++){
            a[j]+=max1%2;
            max1/=2;
        }
        for(int k=0;k<j;k++){
            if(a[k]&&b[k]) c[k]=1;
            s+=c[k]*pow(2,k);
        }
    }
    printf(".0lf",s);
    return 0;
}
