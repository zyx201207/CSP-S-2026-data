#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n;
long long m;
int a[N],b[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    double d=0.0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        d+=a[i];
    }
    sort(a+1,a+n+1);
    d/=n;
    int minn=0x3f3f3f3f,t;
    for(int i=1;i<=n;i++){
            if(abs(a[i]-d)<minn){
                minn=abs(a[i]-d);
                t=i;
            }
    }
    long long sum=0;
    int x=a[t];
    for(int i=1;i<=n;i++){
        int c=abs(a[i]-x);
        m-=c;
        if(m>=0){
            sum++;
        }
    }
    cout<<sum;
    return 0;
}
