#include <bits/stdc++.h>
using namespace std;
int n,m;
int main(){
    freopen("card.in";"r";stdin);
    freopen("card.out";"w";stdout);
    cin>>n>>m;
    int a[n];
    for(int i=0;i<n;i++){
      cin>>a[i];
    }
    cout<<n<<" "<<m<<" "<<a[0];
    return 0;
}
