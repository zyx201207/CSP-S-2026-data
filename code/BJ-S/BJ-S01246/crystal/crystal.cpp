#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<int> a;
    for(int i=1;i<=n;i++){
        int a1;
        cin>>a1;
        a.push_back(a1);
    }
    sort(a.begin(),a.end());
    int len=a[1]-a[0];
    m/=len;
    //cout<<m<<endl;
    for(int i=n;i>=1;i--){
            //cout<<m-n+i<<"      ";
        if(m-n+i<0){
            //cout<<endl;
            //cout<<n-i<<endl;
            return 0;
        }
        else{
            m-=n-i;
        }
    }
    cout<<n;
    return 0;
}