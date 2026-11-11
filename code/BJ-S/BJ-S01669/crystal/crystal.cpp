#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m,a[N];
    cin>>n>>m;
    long long b[n][n]={0},ans[n]={0},num[n]={0};
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    bool flag=true;
    int k=a[2]-a[1];
    for(int i=1;i<=n-1;i++){
        if(a[i+1]-a[i]!=k){
            flag=false;
            break;
        }
    }
    if(flag){
        for(int i=n;i>=1;i--){
            if(num[1]+(n-i+1)*k<=m){
                num[1]+=(n-i+1)*k;
                ans[1]++;
            }
        }
        cout<<ans[1]+1;
        return 0;
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            b[i][j]=a[j]-a[i];
        }
    }
    for(int i=1;i<=n;i++){
        int x=i;
        for(int j=2;j<=n;){
            if(num[i]+b[x][j]<=m){
                num[i]+=b[x][j];
                ans[i]++;
            }
            if(x==1){
                break;
            }
            j++;
            x--;
        }
    }
    int maxx=-999;
    for(int i=1;i<=n;i++){
        if(ans[i]>=maxx){
            maxx=ans[i];
        }
    }
    cout<<maxx+1;











    fclose(stdin);
    fclose(stdout);
    return 0;
}
