#include<bits/stdc++.h>
using namespace std;
    long long s[500005];
    long long a[500005];
    long long ans=-1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long n,m;
    cin>>n>>m;

    for(int i=1;i<=n;i++){
            cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
    }
    if(m>=s[n-1]){
        cout<<n;
        return 0;
    }
    int temp=a[2]-a[1];
    int f=0;
    int ff=0;
    for(int i=1;i<=n;i++){
        if(a[i]==i){
            ff=1;
        }
        else {
        ff=9;
        break;
        }
    }
    for(int i=1;i<=n;i++){
        if(a[i]-a[i-1]!=temp){
            f=1;
            break;
        }
    }
    int maxs=1;
    int sum=0;
    long long fg=0;
    if(ff==1){//a[i]=i   A
            //cout<<"enter A";
        for(int i=1;i<=n;i++){
            if(m/s[i]>0)maxs=i;
            else {
                cout<<maxs;
                return 0;
            }
        }
    }

    else if(f==0&&ff==9){//dengchashulie  B
            //cout<<"enter B";
        for(int i=1;i<n;i++){
            if(m-(temp*(i-1)+sum)>0){
                sum+=temp*(i-1);
            }
            else{
                cout<<i;
                return 0;
            }
        }
    }
    else{
            //cout<<"enter C";
    long long j=1;
    for(int i=1;i<=n;i++){
        if(m>=a[i]*a[i-j+1]-(s[i]-s[j-1]))ans=max(ans,i-j+1);
        else j++;
    }
    cout<<ans;
    }
return 0;}
