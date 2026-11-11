#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans=1,bl=0,ans1=1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    while(m>0){
        if(a[bl]==a[bl+1]){
            bl++;
            ans++;
        }
        else{
            m=m-bl;
            a[bl]++;
        }
    }
    while(m>=0){
        if(a[n-ans1]==a[n-1-ans1]){
            ans++
        }
        else{
            a[n-1-ans1]++;
            m=m-ans1;
        }
    }
    cout<<max(ans.ans1);
    return 0;
    }
