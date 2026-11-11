#include<bits/stdc++.h>
using namespace std;
int n;
long long d;
bool seq=1;
long long a[500005],mx=-0x3f3f3f3f3f3f3f3f,mi=0x3f3f3f3f3f3f3f3f,m,ans=-0x3f3f3f3f3f3f3f3f;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        mi=min(mi,a[i]);
        mx=max(mx,a[i]);
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        if(i>=3&&a[i]-a[i-1]!=a[i-1]-a[i-2]){
            seq=0;
        }
    }
    /*
    int Sum=0;
    for(int i=-100;i<=100;i++){
        Sum+=M[i];
        cout<<i<<" "<<M[i]<<" "<<Sum<<endl;
    }
    cout<<"\n\n\n";
    */
    if(seq==1){
        d=a[2]-a[1];
        if(d>0){
            long long sum=0;
            for(int i=n-1;i>=1;i--){
                sum+=a[n]-a[i];
                if(sum>m){
                    cout<<n-i;
                    return 0;
                }
            }
        }else if(d<0){
            long long sum=0;
            for(int i=1;i<=n;i++){
                sum+=a[1]-a[i];
                if(sum>m){
                    cout<<i-1;
                    return 0;
                }
            }
        }
    }
    for(long long tar=mi-1;tar<=mx+1;tar++){
        long long sum=0,con=0;
        int mxi;
        for(int i=1;i<=n;i++){
            if(a[i]<=tar){
                sum+=tar-a[i];
                con++;
                mxi=i;
            }
        }
        if(sum<=m){
            ans=max(ans,con);
        }else{
            con=0,sum=0;
            for(int i=mxi;i>=1;i--){
                sum+=tar-a[i];
                if(sum>m)break;
                con++;
            }
            ans=max(ans,con);
        }
        //cout<<"tar="<<tar<<" sum="<<sum<<" ans="<<ans<<" con="<<con<<endl;
    }
    cout<<ans;
    /*
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j){
                continue;
            }
            int l=i,r=i;
            while(1)
            if(a[i]-a[l]>a[r]-a[i]){

            }else{
                ;
            }
        }
    }
    */
    return 0;
}

/*
n^2 version
meijv a[i] que ding n
O(mn)
kaolv erfen
con dan diao di zeng
*/
