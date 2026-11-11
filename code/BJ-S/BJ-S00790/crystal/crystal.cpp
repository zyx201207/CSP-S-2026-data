#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    unsigned long long int n,m;
    cin>>n>>m;
    unsigned long long int sum=0,num=n;
    long long int a[n];
    cin>>a[0];
    for(unsigned long long int i=1;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    for(unsigned long long int i=1;i<n;i++){
        sum+=((a[i]-a[i-1])*i);
        if(sum>m){
            num=i;
        }
    }
    cout<<num;
    return 0;
}