#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,a[2000002],ma=-1;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=1;i<=n-m+1;i++){
        for(int j=i+m-1;j<=n;j++){
        int sum=a[i];
            for(int k=i;k<=j;k++){
                sum=sum&a[k];
            }
            ma=max(ma,sum);
            sum=0;
        }
    }
    cout << ma;
    return 0;
}