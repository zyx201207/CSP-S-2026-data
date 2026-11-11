#include<bits/stdc++.h>
using namespace std;
long long a[500001];
int main()
{
    long long n,m,ans=0;
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            for(int o=j;o<=n;o++){
                if(a[i]>a[j]) {
                    long long t=a[i];
                    a[i]=a[j];
                    a[j]=t;
                }
            }
        }
        for(int j=1;j<n;j++){
            if(a[j]==a[j+1]){
                a[j]=a[j];
                for(int o=j;o<n;o++){
                    a[o+1]=a[o+2];
                }
            }
        }
        if(a[1]!=a[2]) {
            if(m-=(a[2]-a[1])>=0){
                a[1]=a[2];
                ans++;
            }
        }
    }

    cout<<ans<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
