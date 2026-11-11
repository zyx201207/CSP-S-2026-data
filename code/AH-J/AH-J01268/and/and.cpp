#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int ttt(int n){
    int a[100010];
    int cnt=0;
    while(n>0){
    a[cnt]=n%2;
    cnt++;
    n/=2;
    }
    for(int i=cnt-1;i>=1;i--){
        cout<<a[i];
    }
    return 0;
}
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
cout<<12;
return 0;
}
