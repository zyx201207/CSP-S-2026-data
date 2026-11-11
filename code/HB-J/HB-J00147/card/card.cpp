#include<bits/stdc++.h>
using namespace std;
const int N=50005;
long long a[N],b[N],cnt[N];
int dj[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        memset(b,0,sizeof b);
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(a[j]==1){
                int k=0;
                while((k++)<i) dj[k]=0;
            }
            dj[i]=a[j];
        }
        for(int i=1;i<=n;i++){
            if(dj[i]!=0){
                cnt[dj[i]]++;
            }
        }
        for(int i=1;i<=n;i++){
            dj[i]=0;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<" ";
    }
    return 0;
}

