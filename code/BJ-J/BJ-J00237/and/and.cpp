#include<iostream>
#include<cstring>
using namespace std;
const int N=2e5+1;
int n,m,cnt0[40],cnt1[40];
long long a[N],sum,ans;
inline bool solve(long long x){
    for(int i=0;i<=38;i++){
        if((x>>i)&1){
            if(cnt1[i]<m){
                return 0;
            }
        }
        else{
            if(!cnt0[i]){
                return 0;
            }
        }
    }
    return 1;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum=sum+a[i];
        for(int j=0;j<=38;j++){
            if((a[i]>>j)&1){
                cnt1[j]++;
            }
            else{
                cnt0[j]++;
            }
        }
    }
    /*for(int i=0;i<=40;i++){
        cout<<cnt0[i]<<" "<<cnt1[i]<<"\n";
    }*/
    long long l=0,r=sum;
    while(l<=r){
        long long mid=l+(r-l)/2;
        if(solve(mid)){
            l=mid+1;
            ans=mid;
        }
        else{
            r=mid-1;
        }
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
}
