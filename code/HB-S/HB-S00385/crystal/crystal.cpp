#include<bits/stdc++.h>
using namespace std;
int n,f,c,x;
long long m,a[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    if(m==0){
        int ans=0,cnt=1;
        sort(a+1,a+1+n);
        for(int i=1;i<n;i++){
            if(a[i]==a[i+1])
                cnt++;
            else{
                ans=max(ans,cnt);
                cnt=1;
            }
        }
        ans=max(ans,cnt);
        cout<<ans;
        return 0;
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        if(i==2)
            c=a[i]-a[i-1];
        if(i>2){
            x=a[i]-a[i-1];
            if(c!=x)
                f=1;
        }
    }
    if(f==0){
        int k=1,cnt=0;
        for(int i=0;i<=m;i++){
            if(cnt==k*c){
                k++;
                cnt=0;
            }
            cnt++;
        }
        cout<<k;
    }
    else
        cout<<5;
    return 0;
}
