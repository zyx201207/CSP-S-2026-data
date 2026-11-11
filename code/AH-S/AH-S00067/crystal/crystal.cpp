#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    long long l=1,r=1,sum=0,ans=1;
    while(r<n){
        //cout<<"sumfirst:"<<sum<<endl;
        if(sum+((a[r+1]-a[r])*(r-l+1))<=m){
            r++;
            sum=sum+((a[r]-a[r-1])*(r-l));
            ans=max(ans,r-l+1);
            //cout<<l<<" "<<r<<endl;
        }else{
            sum=sum-(a[r]-a[l]);
            l++;
        }
        //cout<<"sumnow:"<<sum<<endl;

    }
    cout<<ans;
    return 0;
}
