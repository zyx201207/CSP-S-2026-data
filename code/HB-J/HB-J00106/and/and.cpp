#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m,a[100010],answer;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    sort(a,a+n);
    answer=a[n-1];

    for(int i=n-2;i>=n-m;i--){
        answer=answer&a[i];
    }

    cout<<answer;
    return 0;
}
