#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n];
    int cnt=0,sum=0;
    if(m==2){
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                sum=max(sum,a[i]&a[j]);
            }
        }
        cout<<sum;
        return 0;
    }
    if(m==n){
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n-1;i++){
            cnt+=a[i]&a[i+1];
        }
        cout<<cnt;
    }
    return 0;
}
