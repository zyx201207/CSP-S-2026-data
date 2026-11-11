#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000000],q=0,t[10000005],p;
bool cmp(int x,int y){
    if(x>y){
        return true;
    }
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    long long p=a[n/2];
    for(int i=1;i<=n;i++){
        if(a[i]<=p){
            if(m<=0) break;
            q++;
            a[i]=p;
            m-=p-a[i];
        }

    }
    cout<<q+1;
    return 0;
}
