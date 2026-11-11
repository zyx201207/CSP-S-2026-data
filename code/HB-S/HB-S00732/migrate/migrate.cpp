#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,a,j=0,o=0;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    //cin>>c>>t;
    scanf("%d%d",&c,&t);
    while(t--){
        //cin>>n>>d;
        scanf("%d%d",&n,&d);
        for(int i=1;i<=n;i++){
            //cin>>a;
            scanf("%d",&a);
        if(a%2==0)o+=a;
        else j+=a;
        }
        if(abs(o-j)%2==1){
            printf("%d",abs((o-j)/2)+1);
        }else{
            printf("%d",abs((o-j)/2));
        }
    }

    return 0;
}
