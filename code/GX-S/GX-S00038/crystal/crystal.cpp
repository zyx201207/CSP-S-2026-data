#include<bits/stdc++.h>
using namespace std;
long long a[500001];
int main(){
    freopen("crystal3.in","r",stdin);
    //freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    long long ans=0;
    for(int i=1;i<=n;i++){
        long long y=a[i],tmp=m,ans1=0;
        cout<<a[i]<<endl;
        for(int j=i;j>0;j--){
            //cout<<"    "<<j<<endl;
            if(tmp>=(y-a[j])){
                tmp-=(y-a[j]);
                //cout<<"        "<<tmp<<' '<<y-a[j]<<' '<<ans<<endl;;
                ans1++;
            }
            else
                break;
        }
        //cout<<i<<' '<<ans<<endl<<endl;
        ans=max(ans,ans1);
    }
    cout<<ans;
    return 0;
}
