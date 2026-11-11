#include <bits/stdc++.h>
using namespace std;
int n;
int num[200005];
long long sum;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>num[i];
    }
    for (int i=1;i<=n;i++){
        sum+=num[i];
    }
    cout<<sum/2;
    return 0;
}
