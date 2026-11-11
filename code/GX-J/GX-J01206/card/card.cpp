#include <cstdio>
#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    int n,m;
    cin>>n>>m;
    int a[100005]={0};
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    int sum=n/3;

    for(int i=n-1;i>0;i-=sum){
        cout<<a[i];
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
