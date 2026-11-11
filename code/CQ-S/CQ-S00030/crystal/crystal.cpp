#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    long long m;
    if(!(cin>>n>>m))return 0;
    vector<long long>a(n);
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    vector<long long>prefix(n+1,0);
    for(int i=0;i<n;i++){
        prefix[i+1]=prefix[i]+a[i];
    }
    int max_k=0;
    int left=0;
    for(int right =0;right<n;++right){
        long long k=right-left+1;
        long long cost=k*a[right]-(prefix[right+1])-prefix[left];
        while (cost>m && left <= right){
            left++;
            k=right-left+1;
            if (left<=right){
                cost=k*a[right]-(prefix[right+1]-prefix[left]);
            }
        }
        if (left <=right){
            max_k=max(max_k,right-left+1);
        }
    }
    cout<<max_k;
    return 0;



}
