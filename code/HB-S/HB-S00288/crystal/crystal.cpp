#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans;
int best(int x){
    int aa=1,mm=m;
    while(mm>0){
        if(x=0) break;
        if(a[x]-a[x-1]<=mm){
            mm-=a[x]-a[x-1];
            aa++;
            x--;
        }
        else break;
    }
    return aa;
}
bool cmp(int x,int y){
    return a[x]<a[y];
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n,cmp)
    for(int i=0;i<n;i++){
        if(best(i)>ans) ans=best(i);
    }
    cout<<ans;
    return 0;
}
