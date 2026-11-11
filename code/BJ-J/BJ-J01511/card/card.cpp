#include<iostream>
using namespace std;
const int N=5e5+10;
int n,m,a[N],b[N],ans[300010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int t=0;
        for(int j=i;j<=n;j++){
            bool op=0;
            for(int k=1;k<=t;k++){
                if(op) b[k]=0;
                else if(b[k]==a[j]){
                    op=1;
                    t=k;
                }
            }
            if(!op) b[++t]=a[j];
        }
        for(int j=1;j<=t;j++){
            ans[b[j]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}
