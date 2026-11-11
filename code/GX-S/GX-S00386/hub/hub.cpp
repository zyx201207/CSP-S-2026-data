#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    long long n,m;
    long long mid=0;
    long long it[100009];
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>it[i];
        if(i==0||i==n-1)mid+=it[i];
    }
    sort(it,it+n);
    mid=mid/2;
    vector<long long> a;
    for(int i=0;i<n;i++){
        a.push_back(it[i]-mid);
    }
    int sum=0;
    sort(a.begin(),a.end());
    for(int i=0;i<n;i++){

        int d=it[1]-it[0];
        sum+=abs(a[i])/d;
        if(sum>=m)break;
    }
    cout<<sum-1;
    return 0;
}
