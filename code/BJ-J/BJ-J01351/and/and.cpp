#include<bits/stdc++.h>
using namespace std;
long long a[200010];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(long long i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    if(m==1){
        cout<<a[n-1];
        return 0;
    }
    long long ans=0;
    long long andd;
    for(long long i=0;i<n-m+1;i++){
        andd=a[i];
        for(long long j=i+1;j<i+m;j++){
            andd=andd&a[j];
        }
        //cout<<andd<<endl;
        ans=max(andd,ans);
    }
    cout<<ans;
    return 0;
}
