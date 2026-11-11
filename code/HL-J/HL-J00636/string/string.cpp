#include <bits/stdc++.h>
using namespace std;
long n;
int arr;
int a[200005];
char c[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","r",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>a[i]>>c[i];
        if(c[i]!=c[i]-1){
            arr+1;
        }
    }
    if(arr==1){
        cout<<"0";
    }





    return 0;

}
