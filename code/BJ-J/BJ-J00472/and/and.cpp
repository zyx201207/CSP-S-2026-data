#include<bits/stdc++.h>
using namespace std;
long long n,m,maxn=0,c=0;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    vector<long long>a(n+1);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=n;i>=0;--i){
        long long t=maxn|(1LL<<i);
        //cout<<t;
        c=0;
        for(int j=0;j<n;++j){
            if((a[j]&t)==t)c++;
        }
        if(c>=m)maxn=t;
    }
    cout<<maxn;
    return 0;
}
