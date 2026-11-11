#include<bits/stdc++.h>
using namespace std;
int n,m,arr[1000000],ans;
bool compare(int x,int y){
    return x>y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>arr[i];
    sort(arr,arr+n,compare);
    ans=arr[0];
    for(int i=0;i<m;i++)ans&=arr[i];
    cout<<ans;
}
