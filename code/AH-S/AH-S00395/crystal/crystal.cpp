#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
int N,M;
int a[500005];
bool check(int x){
    int sum=0;
    for(int i=1;i<=N;i++){
        if(a[i]>x)  break;
        sum+=(x-a[i]);
    }
    return sum<=M;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>N>>M;
    for(int i=1;i<=N;i++){
        cin>>a[i];
    }
    sort(a+1,a+N+1);
    int l=-1e12,r=1e12,ans;
    while(l<=r){
        int mid=l+r>>1;
        if(check(mid)){
            ans=mid;
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    for(int i=1;i<=N;i++){
        if(a[i]>ans){
            cout<<i-1;
            return 0;
        }
    }
    cout<<N;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
