#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int main(){
    freopen("crystal.in","r",stdin);                                              
    freopen("crystal.out","w",stdout);
    long long n,m,a[N],qzh[N],xxx;
    bool yn=true;
    qzh[0]=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i==2){
            xxx=a[2]-a[1];
        }
        if(a[i]-a[i-1]!=xxx){
            yn=false;
        }
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        qzh[i]=qzh[i-1]+a[i];
    }
    long long ans=0;
    for(int i=1;i<=n;i++){
        if(yn&&i!=n){
            continue;
        }
        long long total=0,an=1;
        for(int j=i-1;j>=1;j--){
            total+=a[i]-(qzh[j]-qzh[j-1]);
            //cout<<i<<" "<<j<<" "<<total<<endl;
            if(total>m){
                an=i-j;
                break;
            }
            if(j==1){
                an=i;
            }
        }
        ans=max(ans,an);
    }              
    cout<<ans<<endl;
    return 0;
}