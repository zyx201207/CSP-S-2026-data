#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,a[500010];
bool deleted[500010];
void solve(long long used,long long merged){
    for(long long i=1;i<=n;i++){
        for(long long j=1;j<=n;j++){
            if(i!=j&&!deleted[i]&&!deleted[j]){
                if(a[i]==a[j]){
                    a[i]=a[i]+a[j];
                    deleted[j]=1;
                    //cout<<"Merged:"<<i<<' '<<j<<' '<<a[i]<<a[j]<<"->";
                    solve(used,merged+1);
                    a[i]=a[i]-a[j];
                    deleted[j]=0;
                }
            }
        }
    }
    if(used<m){
        for(long long i=1;i<=n;i++){
            if(!deleted[i]){
                a[i]++;
                //cout<<"cped:"<<i<<' '<<a[i]-1<<"->";
                solve(used+1,merged);
                a[i]--;
            }
        }
    }
    ans=max(ans,merged);
    //cout<<endl<<"<<"<<endl;
    return;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
        //cout<<"READ:"<<i<<endl;
    }
    //cout<<"READ.";
    solve(0,0);
    cout<<ans;
    return 0;
}
