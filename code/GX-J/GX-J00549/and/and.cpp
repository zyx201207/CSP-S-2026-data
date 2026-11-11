#include<iostream>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    long long a[200005];
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    long long maxi=-1;
    for(int i=1;i<=n;i++){
        long long sum=a[i];
        for(int j=i;j<=m;j++){
            sum&=a[j];
            cout <<sum<<" ";
        }
        if(sum>maxi){
            maxi=sum;
        }
    }
    cout <<maxi;
}
