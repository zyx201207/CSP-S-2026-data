#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000001],average=0,goal=-2147483647,ans=0;
long long findnearest(long long x){
    long long point=-2147483647;
    for(long long i=1;i<=n;i++){
        if(a[i]!=x&&a[i]<x) point=max(point,i);
    }
    return point;
}
int main(){
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
        average+=a[i];
    }
    average=average/n+1;
    for(long long i=1;i<=n;i++){
        goal=abs(average-a[i])<abs(average-goal)?a[i]:goal;
    }
    while(m>0){
        a[findnearest(goal)]++;
        m--;
    }
    for(int i=1;i<=n;i++){
        if(a[i]==goal) ans++;
    }
    cout<<ans<<endl;
    return 0;
}
