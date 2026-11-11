#include<bits/stdc++.h>
using namespace std;
const int MAXN=100005;
long int n,m;
long int a[MAXN];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            if(a[j]<a[j+1]) swap(a[j],a[j+1]);
        }
    }
    int max1=0;
    for(int i=0;i<n-1;i++){
        int sum=1,x=0;
        for(int j=i+1;j<n;j++){
            x=x+a[i]-a[j];
            if(x<=m) sum++;
            else break;
        }
        if(sum>max1) max1=sum;
    }
    cout<<max1;
    return 0;
}
