#include<bits/stdc++.h>
using namespace std;
int n;
long long a[500005],sum;
long long m;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i = 1;i<=n;i++){
        sum = 0;
        for(int j = 1;j<i;j++){
            sum += a[i] - a[j];
        }
        if(sum >= m){
            int k = i;
            do{
                k++;
            }while(a[k] == a[i]);
            cout<<k-1;
            return 0;
        }
    }
    cout<<n;
    return 0;
}
//²»¸øAC¾Íµ·µ°
