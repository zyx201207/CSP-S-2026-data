#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long ans=0;
int a[500010];
void S(int x){
    long long sum=1;
    long long ml=m;
    int y=a[x];
    for(int i=x-1;i>=0&&ml>0;i--){
        if(y-a[i]>ml)
            continue;
        ml=ml-(y-a[i]);
        sum++;
    }
    ans=max(ans,sum);
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=n-1;i>=0;i--)
        S(i);
    cout<<ans;
    return 0;
}
