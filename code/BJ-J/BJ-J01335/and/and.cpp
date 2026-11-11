#include<bits/stdc++.h>
using namespace std;
int n,m,a[200002],ans,tmp,maxai;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",a+i);
        maxai=max(maxai,a[i]);
    }
    if(m==1){
        printf("%d\n",maxai);
    }
    else if(m==2){
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                ans=max(ans,a[i]&a[j]);
        printf("%d\n",ans);
    }
    else if(n==m){
        for(int i=1;i<=n;i++)ans=ans&a[i];
        printf("%d\n",ans);
    }
    else if(maxai<=4){

    }
    else if(n<=20){

    }
    else if(m==n-1){
        
    }
} 