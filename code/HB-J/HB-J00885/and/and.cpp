#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    long long a[n]={0};
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    if(m==1){
        int s=0;
        for(int i=0;i<n;i++){
            if(a[i]>s){s=a[i];}
        }
        cout<<s;
        return 0;
    }
    if(m==n){
            int ss=a[1];
        for(int i=0;i<n;i++){
            ss=ss&a[i];
        }
        cout<<ss;
        return 0;
    }
    int max=a[0]&a[1];
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i]&a[j]>max){max=a[i]&a[j];}
        }
    }
    cout<<max;
    return 0;
}
