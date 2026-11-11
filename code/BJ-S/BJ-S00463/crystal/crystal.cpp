#include<bits/stdc++.h>
using namespace std;
long long a[500000+10];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int c[500000+10];
    for(int i=1;i<=n-1;i++){
        c[i]=a[i+1]-a[i];
    }
    long long ans=1;
    for(int i=1;i<=n;i++){
        long long j=i,last=m,cnt=0;
        while(j>=1&&last>=0){
            last-=a[i]-a[j];
            if(last>=0)cnt++;
            j--;
        }
        ans=max(ans,cnt);
    }
    cout<<ans;




    return 0;
}
