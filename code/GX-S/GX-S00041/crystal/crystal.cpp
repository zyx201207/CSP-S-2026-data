#include<bits/stdc++.h>
using namespace std;
long long a[100005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m,cz,sum=0,ans=0;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    cin>>a[i];
    sort(a,a+n+1);
    int mid=a[n/2];
    while(sum<=m){
        for(int j=n/2;j>=0;j--){
            cz=mid-a[j-1];
            a[j-1]=a[j-1]+cz;
            sum+=cz;
        }
    }
    for(int p=0;p<n;p++){
        if(a[p]==mid)ans++;
    }
    cout<<ans;
    return 0;
}
