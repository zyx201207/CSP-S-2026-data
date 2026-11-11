#include<bits/stdc++.h>
#define N 500005
using namespace std;
int n,ans;
long long a[N],m,tmp,src,sum,cnt;
bool flag=1;
void specil(){
    src=a[2]-a[1];
    sum=0,cnt=1;
    while(1){
        sum+=src*cnt;
        if(sum>m) break;
        cnt++;
    }
    cout<<cnt;
    return;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i>2&&a[i]-a[i-1]!=a[i-1]-a[i-2]) flag=0;
    }
    if(flag){
        specil();
        return 0;
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        tmp=0;
        for(int j=i-1;j>=1;j--){
            tmp+=(a[i]-a[i-j]);
            if(tmp>m){
                ans=max(ans,i-j);
                break;
            }
            if(j==1){
                ans=max(i,ans);
            }
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
