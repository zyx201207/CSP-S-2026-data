#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n=0,m=0,c=0;
    cin>>n>>m;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=1;i<n;i++){
            while(a[i]!=a[i+1]){
        for(int j=0;j<=i;j++){
            a[j]++;
            m--;

            }
        }
        if(m<=0){
            c=++i;
            break;
            }
    }
    cout<<c;
    return 0;

}