#include<bits/stdc++.h>
using namespace std;
int a[500005];
int del[5005][5005];
int maxn=-1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int m,n;
    cin>>n>>m;
    int m1;
    m1=m;

    int sum=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
    }

    sort(a+1,a+n+1);

    if(sum+m>=n*a[n]){
        cout<<n<<'\n';
        return 0;
    }else{
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                del[i][j]=a[j]-a[i];
                cout<<del[i][j]<<' ';
            }
            cout<<'\n';
        }
        /*for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(a[j]-a[i]<0){
                    del[i][j]=a[j]-a[i];

                }
                cout<<del[i][j]<<' ';
            }
            cout<<'\n';
        }*/
        for(int i=2;i<=n;i++){
            int ans=1,m=m1;
            for(int j=i-1;j>=1;j--){
                if(m+del[i][j]>=0){
                    m=m+del[i][j];
                    ans++;
                }
                cout<<m<<' ';

            }
            cout<<endl;
            maxn=max(maxn,ans);
        }
    }
    cout<<maxn<<'\n';
    return 0;

}
