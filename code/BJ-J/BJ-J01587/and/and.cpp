#include<bits/stdc++.h>
using namespace std;
int n,m,s;
long long a[200010];
int main(){
    freopen("and.in",'r',stdin);
    freopen("and.out",'w',stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    s=a[n];
    for(int i=n-1;i>n-m;i--){
        s=s & a[i];
    }
    cout<<s;
    return 0;
}
