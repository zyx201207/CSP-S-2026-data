#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    int n,m;
    cin>>n>>m;
    long long a[n]={0};
    long long b[m]={0};
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=0;i<m;i++){
        b[i]=a[n-1-i];
    }
    int sum=b[0];
    for(int i=1;i<m;i++){
        sum=sum&b[i];
    }
    cout<<sum;
    return(0);

    fclose(stdin);
    fclose(stdout);
}
