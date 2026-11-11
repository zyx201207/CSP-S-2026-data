#include<bits/stdc++.h>
using namespace std;
int n,a[10000010],m,summ;
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    summ=a[n];
    for(int i=n-1;i>=n-m+1;i--){
        summ=summ&a[i];
    }
    cout<<summ<<endl;
    return 0;
}
