#include <bits/stdc++.h>
using namespace std;
int a[100001];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin >> n >> m;
    string sum = 0;
    for(int i= 0;i <= 2;i++){
        cin >> a[i];
        if(a[i]<0){
            a[i] = -(a[i]);
            sum += a[i];
        }
        else if(a[i]>0){
            sum+=a[i];
        }
        else if(a[i]=0){
            sum += a[i];
        }
    }
    cout << sum;
    return 0;
}