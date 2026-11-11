#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll x[5000];
int m[10000000];
int c,t;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        long long n,d;
        for(int i=0;i<n;i++){
            cin>>x[i];
        }
        for(int i=0;i<n-1;i++){
            for(int j=i;j<n;j++){
                m[x[j]-x[i]]++;
            }
        }
        for(long long i=0;i<=10000000 && i<=d;i++){
            if(m[i]!=0){
                cout<<m[i]<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
