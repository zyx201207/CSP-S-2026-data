#include<bits/stdc++.h>
using namespace std;
    long long a[200010],n,x,b[338332];

int main(){
    freopen("and.in", "r",stdin);
    freopen("and.out","w",stdout);

    cin>>n>>x;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    long long m=-934811322;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i]&a[j]>=m)m=a[i]&a[j];
        }
    }
    cout<<m;
    return 0;
}
