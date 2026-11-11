#include<iostream>
using namespace std;

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    long long a[500005];
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    long long cnt=1;
    for(int i=0;i<n;i++){
        long long d=a[i];
        for(int j=i+1;j<n;j++){
            d+=a[j];
            long long b=j-i+1;
            long long c=a[j]*b-d;
            if(c<=m){
                if(b>cnt){
                    cnt=b;
                }
            }

        }
    }
    cout<<cnt;
    return 0;
}
