#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,a[200000],max[200000],z[200000];
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
        z[i]=a[i];
    }

    for(int i=0;i<m;i++){
        max[i]=0;
        for(int j=1;j<n;j++){
            if(a[j]>a[max[i]])max[i]=j;
        }
        for(int k=max[i];k<n;k++)a[k]=a[k+1];
        n-=1;
        max[i]+=i;
    }
    cout<<z[max[m-1]];
    return 0;
}
