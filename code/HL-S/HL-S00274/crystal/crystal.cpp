#include <bits/stdc++.h>
using namespace std;

long long n;
long long m;
long long res;

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    vector<long long>arr(n,0);
    for(long long i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end(),greater<long long>());
    for(long long i=0;i<n;i++){
        long long x=arr[i];
        long long temp_m=m;
        long long temp_res=0;;
        for(long long j=i;j<n;j++){
            temp_m-=x-arr[j];
            if(temp_m<0){
                break;
            }
            temp_res++;
        }
        res=max(temp_res,res);
    }
    cout<<res;





    return 0;
}
