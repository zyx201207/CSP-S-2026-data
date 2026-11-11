#include<bits/stdc++.h>
using namespace std;
int a[200001],cnt,c[200001];
long long b[55];
bool flag=false;
bool flag13=true;
bool flag1112=true;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    b[0]=1;
    for(int i=1;i<=50;i++)b[i]=b[i-1]*2;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]>=4)flag1112=false;
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        for(int k=1;k<=50;k++){
            if(b[k]==a[i]){
                c[i]=k;
                break;
            }
            if(b[k]!=a[i]-1)flag13=false;
        }
    }
    if(flag1112){
        long long ans=a[n];
        for(int i=n-1;i>=n-m+1;i--)ans&=a[n];
        cout<<ans;
    }
    if(flag13){
        long long ans=a[n];
        for(int i=n-1;i>=n-m+1;i--)ans&=a[n];
        cout<<ans;
    }
    while(!flag){
        int t=c[n],cntt=1;
        int i;
        for(i=n;i>=1;i--){
            //cout<<i<<' '<<cntt<<endl;
            if(c[i]==c[i-1])cntt++;
            else{
                if(cntt<m){
                    n=i-1;
                    break;
                }
                else{
                    flag=true;
                    break;
                }
            }
        }
        if(i<1){
            if(cntt<m)n=i;
            break;
        }
    }
    int ans=a[n];
    int i;
    for(i=n;cnt<m&&i>=0;i--){
        int ansk=0;
        for(int k=1;k<=50;k++){
            if(b[k]==ans){
                ansk=k;
                break;
            }
        }
        if(ansk!=0&&c[i]!=0&&ansk!=c[i]||abs(ansk-c[i])>1){
            //cout<<i<<' '<<ans<<' '<<a[i]<<" continue"<<endl;
            continue;
        }
        ans&=a[i];
        cnt++;
        //cout<<i<<' '<<ansk<<' '<<c[i]<<' '<<ans<<' '<<a[i]<<' '<<cnt<<endl;
    }
    if(i<0)cout<<0;
    cout<<ans;
    return 0;
}
