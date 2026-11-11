#include<bits/stdc++.h>;
using namespace std;
int n,m,a[1001],cnt,minn=100000001,minn1,s,t;
int main(){
    freopen("crytal.in","r",stdin);
    freopen("crytal.out","w",stdout);
    cin>>n>>m;
    int t=m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cnt+=a[i];
    }
    cnt=cnt/n+1;
    //cout<<cnt;
    for(int i=0;i<t;i++){
        minn1=0;
        minn=1000000001;
        for(int i=1;i<=n;i++){
            if(a[i]>cnt){
                if(a[i]-cnt<minn&&a[i]-cnt!=0){
                    minn=a[i]-cnt;
                    minn1=i;
                }
            }else{
                if(cnt-a[i]<minn&&a[i]-cnt!=0){
                    minn=cnt-a[i];
                    minn1=i;
                }
            }
        }
        a[minn1]++;
        //cout<<minn<<" "<<minn1<<endl;
    }
    for(int i=1;i<=n;i++){
        if(a[i]==cnt){
            s++;
        }
    }
    cout<<s;
    return 0;
}
