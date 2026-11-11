#include<iostream>
#include<cstdio>
using namespace std;
long long n,a[10005],m,b[10005][10005],ans;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            b[i][j]=a[j]-a[i];
        }
    }
    for(int i=2;i<=n;i++){
        int s=0;
        for(int j=1;j<i;j++){
            s+=b[j][i];
        }
        if(s==m){
            ans=i;
        }
    }
    cout<<ans<<endl;
    return 0;
}
