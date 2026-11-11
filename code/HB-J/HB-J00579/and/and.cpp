#include <bits/stdc++.h>
using namespace std;
const int N=220000;
int n,m,ans,cmp,maxx;
int a[N];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        maxx=max(maxx,a[i]);
    }
    if(m==1){
        for(int i=1;i<=n;i++){
            ans=max(ans,a[i]);
        }
    }else if(m==n){
        ans=a[1];
        for(int i=2;i<=n;i++){
            ans=ans&a[i];
        }
    }else if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                ans=max(ans,a[i]&a[j]);
            }
        }
    }else if(m==n-1){
        for(int i=1;i<=n;i++){
            if(i==1) cmp=a[2];
            else cmp=a[1];
            for(int j=1;j<=n;j++){
                if(j!=i){
                    cmp=cmp&a[j];
                }
            }
            ans=max(ans,cmp);
        }
    }else if(maxx<4){
        int num[4]={0,0,0,0};
        for(int i=1;i<=n;i++){
            num[a[i]]++;
        }
        if(m-a[3]>0){
            m-=num[3];
            if(m-num[1]<=0){
                ans=1;
            }
            if(m-num[2]<=0){
                ans=2;
            }
        }else{
            ans=3;
        }
    }else{
        ans=maxx;
    }
    printf("%d",ans);
    return 0;
}







