//something wrong again but maybe ok
#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,m;
int a[200005]={};
int maxnn[200005]={};
int ans;

signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;++i){
        //cout<<"start"<<i<<endl;
        cin>>a[i];
        //cout<<"get"<<a[i]<<endl;
        if(n==m){
            if(i==0){
                ans=a[i];
            }
            else{
                ans=ans&a[i];
            }
        }
        else{
            if(i<m){
                maxnn[i]=a[i];
            }
            else{
                maxnn[m]=a[i];
            }
            sort(maxnn,maxnn+m+1,[](int a1,int a2){return a1>a2;});
            maxnn[m]=0;
            //cout<<"sort"<<i<<" "<<a[i]<<" "<<maxnn[0]<<endl;
        }
    }
    //cout<<"get"<<endl;
    if(n==m){
        cout<<ans;
        return 0;
    }
    //sort(a,a+n,[](int a1,int a2){return a1>a2;});
    ans=maxnn[0];
    for(int i=1;i<m;++i){
        ans=ans&maxnn[i];
    }
    cout<<ans;
    return 0;
}
