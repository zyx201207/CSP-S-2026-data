#include<bits/stdc++.h>
using namespace std;
const int M=5e5+10,N=3e5+10;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,a[M],b[M],j[N],ans[N];
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    int x;
    for(int i=1;i<=m;i++){
        x=1;
        for(int l=i;l<=n;l++){
            if(j[a[l]]==0){
                j[a[l]]=x;
                b[x++]=a[l];

            }else{
                for(int d=j[a[l]]+1;d<=x;d++){
                    j[b[d]]=0;
                }
                x=j[a[l]];
            }


        }
        for(int l=1;l<=x;l++){
            ans[b[l]]++;
            j[b[l]]=0;
        }
    }
    for(int i=1;i<=m;i++){
        cout << ans[i] << " ";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
