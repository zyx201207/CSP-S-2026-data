#include<bits/stdc++.h>
using namespace std;
long long ans=0;
struct S{
    int sum;
    int x;
}arr[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    char c;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i].sum>>c;
        arr[i].x=(c-'0')-48;
    }
    int i=1,j=n;
    while(true){
        if(arr[i].x!=arr[j].x) ans+=min(arr[i].sum,arr[j].sum);
        if(arr[i].sum>arr[j].sum){
            arr[i].sum-=arr[j].sum;
            j--;
        }else if(arr[i].sum<arr[j].sum){
            arr[j].sum-=arr[i].sum;
            i++;
        }else{
            i++;
            j--;
        }
        if(i>=j) break;
    }
    cout<<ans;
    return 0;
}
