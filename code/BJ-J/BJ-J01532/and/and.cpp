#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    long long maxn=-1,max1=-1;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]>max1){
            max1=a[i];
        }
    }
    if(m==1){
        cout<<max1;
        return 0;
    }
    if(m==2){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j && (maxn<a[i] & a[j])){
                    maxn=a[i] & a[j];
                }
            }
        }
    }else{
        cout<<(a[0] & a[n-2] & a[n-1]);
        return 0;
    }
    cout<<maxn;
    return 0;
}
