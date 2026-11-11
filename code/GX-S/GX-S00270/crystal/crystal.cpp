#include<bits/stdc++.h>
using namespace std;
int n,z,c,d,l=0;
long long m,b;
int main(){


    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    int a[n]={ };
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        if(a[i]>a[i+1]){
            z=a[i];
            a[i]=a[i+1];
            a[i+1]=z;
        }
    }
        for(int i=2;i<n;i++){
                b=10000;
            if(a[i+1]-a[i]<b){
                b=a[i+1]-a[i];
                c=a[i+1];
                d=i;

            }
        }
        for(int i=d;i>=0;i--){
            if(a[d]-a[i]<=m){
                m=m-(a[d]-a[i]);

                l=l+1;
            }
        }

    cout<<l;
    return 0;
}
