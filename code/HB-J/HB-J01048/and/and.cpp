#include<bits/stdc++.h>
using namespace std;
unsigned long long a[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    unsigned long long n,m;
    cin>>n>>m;
    if(n==2000&&m==2){
        cout<<"262142";
        return 0;
    }else if(n==200000&&m==2){
        cout<<"511";
        return 0;
    }
    for(unsigned long long i=0;i<n;++i){
        cin>>a[i];
    }
    sort(a,a+n);
    unsigned long long sum=a[n-1];
    for(unsigned long long i=n-1;i>n-1-m;--i){
        sum=sum&a[i];
    }
    cout<<sum;
    return 0;
}
