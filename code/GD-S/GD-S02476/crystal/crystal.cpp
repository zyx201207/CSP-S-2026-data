#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100000];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int sum=0;
    if(m==0){
        for(int i=0;i<=1;i++){
            if(a[i]==a[i+1]){
                sum++;
            }
        }
    }
    cout<<sum;
    return 0;
}
