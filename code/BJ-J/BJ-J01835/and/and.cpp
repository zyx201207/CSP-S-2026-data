#include<bits/stdc++.h>
using namespace std;

long long n,m,a[200001],b[200001][31];

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        while(a[i]!=0){
            int t=1;
            b[i][t]=a[i]%2;
            a[i]/2;
            t++;
        }
    }
    long long maxn=-1;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            int c[31];
            for(int k=1;k<=31;k++){
                if(b[i][k]==b[j][k])c[k]=1;
                else c[k]=0;
            }
            long long cnt=0;
            for(int k=1;k<=31;k++){
                cnt=c[i]*pow(2,k);
            }
            maxn=max(maxn,cnt);
        }
    }
    cout << maxn;

    return 0;
}
