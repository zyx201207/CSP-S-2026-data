#include<bits/stdc++.h>
using namespace std;
unsigned long long n,m;
long a[500002];
long ans=-LONG_MIN;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    for(long i=0;i<n;){
        long now=m,ans_n=1;
        for(long j=i-1;j>=0;j--){
            if(a[i]-a[j]<=now){
                ans_n++;
                now-=(a[i]-a[j]);
            }else{
                break;
            }
        }
        i++;
        while(i<n && a[i]==a[i-1]) ans_n++,i++;
        ans=max(ans,ans_n);
    }
    cout<<ans;
}

//crystal
