#include <bits/stdc++.h>
using namespace std;
bool a[3005];
int a1[3005];
int ans[3005];
int n,m;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    int s=1;
    for(int i=1;i<=n;i++){
        cin>>a1[i];
    }
    while(s<=n){
        memset(a,0,sizeof(a));
        for(int i=s;i<=n;i++){
            int f=i+2;
            for(int j=i;j>0;j--){
                if(a[j]&&(a1[i]==a1[j])){
                    f=j;
                    break;
                }
            }
            if(f!=i+2)
            for(int j=f;j<=i;j++){
                a[j]=0;
            }
            else a[i]=1;
        }
        for(int i=s;i<=n;i++){
            if(a[i]){
                ans[i]++;
            }
        }
        s++;
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
    fclose(stdin);
    fclose(stdout);
}
