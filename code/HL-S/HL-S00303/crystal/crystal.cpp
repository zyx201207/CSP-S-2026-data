#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long power;
    int number;
    long long arr[100001],brr[100001];
    cin>>number>>power;
    for(int i=0;i<number;i++){
        cin>>arr[i];
    }
    sort(arr,arr+number);
    int x=1,x1=1,ans=-1;
    long long k=power;
    while(number--){
        if(arr[number]==arr[number-1]){
            x++;
            continue;
        }
        for(int i=number-1;i>=0;i--){
            if(k<arr[number]-arr[i]){
                break;
            }else{
                k-=arr[number]-arr[i];
                x++;
            }
        }
        ans=max(ans,x);
        x=1;
        k=power;
    }
    cout<<ans;
    return 0;
}
   