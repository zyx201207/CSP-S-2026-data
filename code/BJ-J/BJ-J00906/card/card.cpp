#include<bits/stdc++.h>
using namespace std;
int us[500005];
int l[500005];
int bo;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>us[i];

    }
    if(n==m){
        for(int i=1;i<=n;i++){
                l[us[i]]=i;

        }
        for(int i=1;i<=n;i++){
            cout<<l[i]<<" ";

        }
        return 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            int fu[500005];
            fu[j]=us[j];
            for(int k=1;k<j;k++){
                if(us[j]=fu[k]){
                    for(int ho=k;ho<j;ho++){
                            fu[ho]=0;
                    }
                    break;
                }
            }
            for(int ho=1;ho<=j;ho++){
                l[fu[ho]]++;
            }
        }
    }
    for(int i=1;i<=m;i++){
            cout<<l[i]<<" ";

    }
    return 0;
}
