#include<bits/stdc++.h>
using namespace std;
int n,g=0;
long long m;
int a[500001],s[500000];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    int x=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];

    }
    int z=0;
    for(int i=1;i<=n-2;i++){
        if(a[i+1]-a[i]==a[i+2]-a[i+1]){
            x++;
            z=a[i+1]-a[i];
        }
    }
    if(x==n-2){
        int l=1;
        for(int i=1;i<=n;i++){
            m-=i*z;
            if(m<0){
                cout<<l;
                return 0;
            }
            l++;
        }
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n-1;i++){
        s[i]=a[i+1]-a[i];
    }
    sort(s+1,s+n);
    int s=1;
    for(int i=2;i<=n;i++){
        while(a[1]<a[i]&&m>0){
            m-=s;
            if(m<0){
                break;
            }
            a[1]++;
        }
        s++;
        g++;
        if(m<=0){
            break;
        }
    }
    cout<<g+1;
    return 0;
}
