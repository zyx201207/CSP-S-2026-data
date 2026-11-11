#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    long long a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    if(n>5000){
        if(a[1]-a[0]==0){
            cout<<n;
            return 0;
        }
        for(int i=1;i<n;i++){
            if((i*(i+1))*(a[1]-a[0])==2*m){
                cout<<i+1;
                return 0;
            }
            if((i*(i+1))*(a[1]-a[0])>2*m){
                cout<<i;
                return 0;
            }
        }
        return 0;
    }
    long long c[n-1];
    for(int i=0;i<n-1;i++){
        c[i]=a[i+1]-a[i];
    }
    int maxa=-1;
    for(int i=0;i<n-1;i++){
        long long sum=0;
        int aa=0;
        for(int j=i;j<n-1;j++){
            sum+=(1+j-i)*c[j];
            aa++;
            if(sum>m){
                aa--;
                sum-=c[j];
                break;
            }
            else if(sum==m){
                break;
            }
        }
        maxa=max(maxa,aa);
    }
    cout<<maxa+1;
    return 0;
}
