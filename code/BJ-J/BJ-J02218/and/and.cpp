#include<bits/stdc++.h>
using namespace std;
int main(){
    long long n,m,a[200005],b[100000];
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    int ans=0;
    for(int i=0;i<m;i++){
        ans+=b[i];
        
    }int j=0;
        while(ans/2>0){
            b[j]=ans%2;
            ans/=2;
            j++;
        }
        if(ans%2!=0)b[j]=ans%2;
        for(int i=0;i<j;i++){
            cout<<b[j];
        }
    return 0;
}
