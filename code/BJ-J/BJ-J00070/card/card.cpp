#include<bits/stdc++.h>
using namespace std;
int n;
int m[500005];
int d[500005],k;
int ans[300003];
bool ans2[300003];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int b;
    cin>>n>>b;
    for(int i=1;i<=n;i++){
        cin>>m[i];
    }
    for(int i=1;i<=n;i++){
        k=0;
        for(int j=i;j<=n;j++){
            d[++k]=m[j];
            for(int a=k-1;a>=1;a--){
                if(d[a]==d[k]){
                    k=a;
                    break;
                }
            }

        }
        for(int j=1;j<=k;j++){
            ans2[d[j]]=1;
 //           cout<<d[j]<<" ";
        }
        for(int j=1;j<=b;j++){
            if(ans2[j]){
                ans[j]++;
            }
            ans2[j]=0;
        }
    }
    for(int i=1;i<=b;i++){
        cout<<ans[i]<<" ";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
