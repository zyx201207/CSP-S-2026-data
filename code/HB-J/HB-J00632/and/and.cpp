#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    //int a=3,b=15;
    //int c=a&b;
    //cout<<c;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int max1=0;
    if(m==2){
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                int x=a[i],b=a[j];
                int c=x&b;
                max1=max(max1,c);
            }
        }
    }
    if(m==1){
        for(int i=1;i<=n;i++)max1=max(max1,a[i]);
    }
    cout<<max1;
    return 0;
}
