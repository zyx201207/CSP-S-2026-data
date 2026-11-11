#include<bits/stdc++.h>
using namespace std;
long long n,m,mx;
long long a[500000+10];
long long b[500000+10];
long long twocut(long long x){
    long long l=x,r=n-1,mid=(l+r)/2;

    while(l<=r){
        mid=(l+r)/2;
        long long q=(a[mid]-a[x])-(b[mid]-b[x])*x;
        //cout<<q<<endl;

        //if(q==m)return mid-x+1;
        if(q<=m){
            l=mid+1;
        }
        else{
            r=mid-1;
            if(r==-1)break;
        }

    }
    //cout<<r<<' '<<x<<endl;
    return r-x+1;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    long long q,w;
    a[0]=0;
    cin>>a[1];
    for(int i=2;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    int h=0;
    for(int i=1;i<n;i++){
        h+=(a[i+1]-a[i])*i;
        b[i]=b[i-1]+(a[i+1]-a[i]);
        a[i]=h;

        //cout<<a[i]<<' '<<b[i]<<endl;
    }
    a[n]=0;
    for(long long i=0;i<n;i++){
        mx=max(mx,twocut(i));

    }
    cout<<mx;
    return  0;
}
