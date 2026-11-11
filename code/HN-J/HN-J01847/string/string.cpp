#include<bits/stdc++.h>
using namespace std;
void print(int *a,int n){
    for(int i=1;i<=n;i++)
        printf("%d ",a[i]);
    printf("\n");
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long int n,ans=0;
    int a[n+1]={ };
    char b[n+1]="";
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d %c",&a[i],&b[i]);
    }
    int i=1,j=n;
    while(i<j){
        if(b[i]!=b[j]){
            ans+=min(a[i],a[j]);
            if(a[i]>a[j]){
                a[i]-=a[j];
                j--;
            }
            else if(a[i]<a[j]){
                a[j]-=a[i];
                i++;
            }
            else{
                j--;
                i++;
            }
            print(a,n);
        }
        else{
            if(a[i]>a[j]){
                a[i]-=a[j];
                j--;
            }
            else if(a[i]<a[j]){
                a[j]-=a[i];
                i++;
            }
            else{
                j--;
                i++;
            }
        }
    }
    printf("%d",ans);
    return 0;
}
