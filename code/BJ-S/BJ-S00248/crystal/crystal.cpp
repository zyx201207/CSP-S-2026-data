#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500010];
long long cha[100010];
long long ans=1;
bool cheak(long long x){
    return ((a[2]-a[1])*(x+1))*x/2<=m;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    //MX-=100;
    //cout<<MX;

    if(n<=5000 && m<=1000000){
        sort(a+1,a+n+1);
        for(int i=1;i<=n;i++){
            for(int j=1;j<i;j++){
                cha[j]=a[i]-a[j];
                //if(cha[j]<0){
                    //cha[j]*=-1;
                //}
            }
            //sort(cha+1,cha+i+1);
            int t=m;
            long long k=1;
            long long ki=i-1;
            while(t>=cha[ki] && ki>=1){
                t-=cha[ki];
                ki--;
                k++;
            }
            if(k>ans){
                ans=k;
                //cout<<i<<" ";
            }
        }
        cout<<ans;

    }else{
        if(a[2]-a[1]<0){
            for(int i=1;i<=n/2;i++){
                swap(a[i],a[n-i+1]);
            }
        }
        long long l=1,r=m;
        while(l<=r){
            long long mid=l+(r-l)/2;
            if(cheak(mid)){
                l=mid+1;
            }else{
                r=mid-1;
            }
            //cout<<"f";
        }
        cout<<l;
    }
    return 0;
}

