#include <bits/stdc++.h>

using namespace std;
int n,m;
int a[500005],st[500005],cnt[300005],ed;

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    scanf("%d %d",&n,&m);

    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);

    }

    for(int i=1;i<=n;i++){
        ed=i;
        memset(st,0,sizeof(st));
        for(int j=i;j<=n;j++){
            st[ed++]=a[j];
             for(int k=i;k<ed-1;k++){
                if(st[k]==a[j]){

                    ed=k+1;
                    break;
                }
            }
        }
        for(int j=1;j<=ed-1;j++){
            cnt[st[j]]++;
        }
    }
    for(int i=1;i<=m-1;i++){
        cout<<cnt[i]<<" ";
    }
    cout<<cnt[m];
    fclose(stdin);
    fclose(stdout);
    return 0;
}
