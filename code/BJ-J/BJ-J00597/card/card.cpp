#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);

    int n,m,dki=0;cin>>n>>m;
    int p[555555],cnt[333333],desk[555555];
    for(int i=1;i<=n;i++)cin>>p[i];
    for(int t=1;t<=n;t++){//ju
        dki=0;
        for(int i=t;i<=n;i++){//pokr p[i]
            int f=0,tmp=-1,x=1;
            for(;x<=dki;x++)
                if(desk[x]==p[i]){
                    f=1;tmp=x;break;
                }
            if(f==0)desk[++dki]=p[i];
            else{
                for(int k=x+1;k<=dki;k++){
                    desk[k]=-1;
                }dki=x+1;
            }
        }for(int i=1;i<=dki;i++){cnt[desk[i]]++;}
    }for(int i=1;i<=m;i++)cout<<cnt[i]<<' ';
    return 0;

}
