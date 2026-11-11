#include <bits/stdc++.h>
using namespace std;
int n,m,ans;
vector<int> a;
int _and(int m,vector<int> a,int num,int j){
    for(int i = j+1;i<=n;++i){
        int number=num&a[i];
        if(m)
            return _and(m-1,a,number,i);
        if(!m)
            return number;
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    a.resize(n+1);
    for(int i = 1;i<=n;++i){
        cin>>a[i];
    }
    for(int i = 1;i<=n;++i){
        int num=a[i];
        num=_and(m-1,a,num,i);
        if(num>ans){
            ans=num;
        }
    }
    cout<<ans;
    return 0;
}
