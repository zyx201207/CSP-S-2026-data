#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
long long a[500005];
long long n,m,ans=-100000000;
long long allplus[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a,a+n+1);
    /*
    for(int i=1;i<=n;i++){
        cout<<a[i]<<endl;
    }
    */
    //cout<<n;
    for(int i=1;i<=n;i++){
        allplus[i]=allplus[i-1]+a[i];
    }
    /*
    for(int i=250000;i<=250100;i++){
        cout<<allplus[i]<<endl;
    }
    */
    for(int i=1;i<=n;i++){
        int carry=a[i]*(i-1)-allplus[i-1];
        //cout<<"carry:"<<carry<<endl;
        if(carry<=m){
            ans=i;
            //cout<<i<<"ok"<<endl;
        }else{
            //cout<<a[i]*(i-1)<<"-("<<allplus[i-1]<<")="<<carry<<endl;
            break;
        }
    }
    cout<<ans;
    return 0;
}
