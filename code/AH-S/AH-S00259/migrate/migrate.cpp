#include<iostream>
using namespace std;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    long long c,t;
    cin>>c>>t;
    long long n[t],d[t],ans[t];
    for(long long i=0;i<t;i++){
        cin>>n[i]>>d[i];
        long long x[n[i]],ed;
        for(long long j=0;j<n[i];j++)cin>>x[j];
        int bl=0;
        for(long long j=1;j<n[i]-1;j++){
            if(x[j]-x[j-1]!=x[j+1]-x[j])bl=1;
            ed=x[j]-x[j-1];
        }
        if(bl==0&&d[i]>=ed)ans[i]=(n[i]-1)/2;
        else ans[i]=0;
    }
    for(long long i=0;i<t;i++)cout<<ans[i]<<endl;
    return 0;
}
