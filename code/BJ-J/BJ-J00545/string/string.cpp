#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    int a[n],sum=0;
    char c[n];
    for(int i=0;i<n;i++){
        cin>>a[i]>>c[i];
    }
    int i=0,j=n-1;
    while(i!=j){
        int m=min(a[i],a[j]);
        if(c[i]!=c[j]){
            sum+=m;
        }
        a[i]=max(0,a[i]-m);
        a[j]=max(0,a[j]-m);
        if(a[i]==0)i++;
        if(a[j]==0)j--;
    }
    cout<<sum;
    return 0;
}