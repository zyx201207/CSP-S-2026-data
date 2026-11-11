#include<bits/stdc++.h>
using namespace std;
long long n;
long long a[500005],diff[500005];
long long m;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    //cout<<m<<'\n';
    if(n==1){
        cout<<1;
        return 0;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=n-1;i>=1;i--){
        diff[i]=a[i+1]-a[i];
    }
    //for(int i=n-1;i>=max(n-50,1);i--){
    //    cout<<diff[i]<<'\n';
    //}
    //cout<<"__________________"<<'\n';
    long long m1,m0;
    long long ans1,ans2=-1;
    for(int i=n;i>=1;i--){
        ans1=1;
        m1=0;
        m0=0;
        for(int j=i-1;j>=1;j--){
            m1+=m0;
            m1+=diff[j];
            if(m1>m){
                break;
                m1-=diff[j];
                m1-=m0;
            }
            ans1++;
            m0+=diff[j];
        }
     //   if(ans1>ans2){
       //   cout<<ans2<<"=>"<<ans1<<"("<<m1<<")"<<"from:"<<i<<'\n';
        //}
        //cout<<'\n';
        ans2=max(ans1,ans2);
    }
    cout<<ans2;
    return 0;
}
/*

*/
