#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int ans[1000005];
long long sum,best;
vector<int> v;
void stl(int n,int m){
    if(v.size()==m){
            sum=v[0]&v[1];
        for(int i=2;i<m;i++){
            sum=sum&v[i];
        }
    best=max(best,sum);
    }
    for(int i=0;i<n;i++){
        if(!ans[i]){
            v.push_back(a[i]);
            ans[i]=1;
            stl(n,m);
            v.pop_back();
            ans[i]=0;
        }
    }
}
int main(){

    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(m==1){
        int maxl=0;
        for(int i=0;i<n;i++){
            maxl=max(a[i],maxl);
        }
        cout<<maxl;
        return 0;
    }
    stl(n,m);
    cout<<best;
}
