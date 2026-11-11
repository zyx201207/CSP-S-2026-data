#include <bits/stdc++.h>
using namespace std;
long long n,m;
const int N=(int) 5*1e5+10;
long long a[N];
long long cha[N];
long long sum[300010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    for(long long step=1;step<=n;step++){
        for(long long i=step;i<=n;i++){
                long long j;
            for(j=i+1;j<=n;j++){
                if(a[j]==a[i]){
                    cha[i]+=1;
                    cha[j]-=1;
                    i=j-1;
                    break;
                }
            }

        }
        int t=0;
        for(long long i=step;i<=n;i++){
            t+=cha[i];
            cha[i]=0;
            if(t==0){
                sum[a[i]]++;
            }

        }
    }
    for(long long k=1;k<=m;k++){
        cout<<sum[k]<<" ";
    }
    return 0;
}
