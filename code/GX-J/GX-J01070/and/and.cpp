#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m,sum;
    long long a[100010];
    cin>>n,m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for (int i=0;i<n;i++){
        for (int j=i+1;j<n;j++){
            sum=a[i] and a[j];
        }
    }
    cout<<sum;
    return 0;
}
