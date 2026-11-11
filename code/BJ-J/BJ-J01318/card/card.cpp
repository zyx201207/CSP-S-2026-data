#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int st[300005]={0};//zbz
int pl[300005]={0};//first
int ans[300005]={0};
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(pl[a[i]]==0){
            pl[a[i]]=i;
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=k;i<=n;i++){
            if(st[a[i]]==0){
                st[a[i]]=1;
                //ans[a[i]]++;
            }else{
                for(int j=pl[a[i]];j<i;j++){
                    if(st[a[j]]==1){
                        //ans[a[j]]--;
                    }
                    st[a[j]]=0;
                }
                pl[a[i]]=i;
                st[a[i]]=1;
                //ans[a[i]]++;
            }
        }
        for(int i=1;i<=m;i++){
            //printf("%d ",st[i]);
            ans[i]=ans[i]+st[i];
            st[i]=0;
        }
        //printf("\n");
    }
    for(int i=1;i<=m;i++){
        printf("%d ",ans[i]);
    }
	return 0;
}

