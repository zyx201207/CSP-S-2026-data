#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
    return x>y;
}
int n,m,a[200005],maxx=-1;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    if(m==1){
        sort(a+1,a+1+n);
        printf("%d",maxx);
        return 0;
    }else if(m==2){
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                if((a[i]&a[j])>=maxx){
                    maxx=a[i]&a[j];
                }
            }
        }
        printf("%d",maxx);
        return 0;
    }else if(m==n){
        maxx=a[1];
        for(int i=1;i<=n;i++){
            maxx=maxx&a[i];
        }
        printf("%d",maxx);
        return 0;
    }else{
        sort(a+1,a+1+n,cmp);
        maxx=a[1];
        for(int i=1;i<=m;i++){
            maxx=maxx&a[i];
        }
        printf("%d",maxx);
    }
    return 0;
}
