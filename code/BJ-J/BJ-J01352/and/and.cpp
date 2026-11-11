#include <iostream>
#include <string>
using namespace std;
int a[200001],b[200001];
/*int fguibin(int l1,int r1){
    if(r1-l1<=1){
        return 0;
    }
    int mid=(l1+r1)/2,l2=l1,r2=r1,i;
    for(i=l1;i<=r1;i++){
        if(a[i]<a[mid]){
            b[l2]=a[i];
            l2++;
        }else{
            b[r2]=a[i];
            r2--;
        }
    }
    b[l2]=a[mid];
    for(i=l1;i<=r1;i++){
        a[i]=b[i];
    }
    fguibin(l1,mid);
    fguibin(mid+1,r1);
    return 0;
}*/
int main(){
    int n,m,i,j,l,r,ans;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
        //b[i]=a[i];
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n-i+1;j++){
            if(a[j]>a[j+1]){
                int t;
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }
  //  l=1;
    //r=n;
    //printf("d");
    //fguibin(l,r);
    ans=a[n]&a[n-1];
    for(i=n-2;i>=n-m+1;i--){
        ans=ans&a[i];

    }
    printf("%d",ans);
    return 0;
}
