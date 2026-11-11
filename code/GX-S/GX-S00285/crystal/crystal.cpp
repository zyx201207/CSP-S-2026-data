#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m,sum=0;
    cin>>n>>m;
    int a[n];
    long long c=m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=n-1;i>=0;i--){
        long long x=0;
        m=c;
        for(int j=i-1;j>=0;j--){
            if(a[i]-a[j]<=m){
                x++;
                m=m-(a[i]-a[j]);
            }else{
                break;
            }
        }
        if(x>sum){
            sum=x;
        }
    }
    cout<<sum+1;
}
