#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    int n,m;
    cin>>n>>m;

    int a[500005];
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int temp[500005];
    int ans[300005];
    for(int i=1;i<=n;i++){
        int l=i;
        for(int j=l;j<=n;j++){
            //a[j];
            bool f=1;
            for(int k=l;k<=j-1;k++){
                if(a[k]==a[j]){
                    l=j;
                    temp[j]=a[j];
                    f=0;
                    break;
                }

            }if(f) temp[j]=a[j];
        }
        for(int t=l;t<=n;t++){
            ans[temp[t]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}
