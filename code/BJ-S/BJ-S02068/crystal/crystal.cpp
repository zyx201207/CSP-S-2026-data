#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long int n,m,a[500005];
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    int max=0;
    for(int i=0;i<n;i++){
        int t=1;
        int sum=m;
        for(int j=i-1;j>=0;j--){
            if((sum-(a[i]-a[j]))<0){
                if(t>max){
                    max=t;
                }
                break;
            }
            sum-=(a[i]-a[j]);
            t++;

        }
        if(t>max){
            max=t;
        }
    }
    cout<<max;
    return 0;
}
