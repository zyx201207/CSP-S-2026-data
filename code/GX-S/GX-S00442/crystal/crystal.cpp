#include <cstdio>
#include <bits/stdc++.h>
using namespace std;
int main(){

    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    int n,m;
    cin>>n>>m;

    int a[10005]={0};
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    int sum=0;

    for(int i=0;i<m;i++){
        if(a[i]+1==a[i+1]){
            a[i]++;
        }
    }

    for(int i = 0;i < n;i++){
        if(a[i]=a[i+1]){
            sum++;
        }
    }

    cout<<sum;


    fclose(stdin);
    fclose(stdout);

    return 0;
}
