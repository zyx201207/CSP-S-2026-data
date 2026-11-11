#include<bits/stdc++.h>
using namespace std;
int n;
long long m,t;
long long mt=LLONG_MIN;
long long it=LLONG_MAX;
long long a[500010];
bool flag=1;
long long cz;
void eA(){
    long long s=m*2;
    s/=cz;
    long long z=sqrt(s);
    if(z*(z+1)>s) z-=1;
    cout<<z+1;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i==2) cz=a[2]-a[1];
        if(a[i]!=i*cz) flag=0;
        mt=max(mt,a[i]);
        it=min(it,a[i]);
    }
    if(flag==1){
        eA();
        return 0;
    }
    sort(a+1,a+n+1);
    for(int p=it;p<=mt;p++){
        long long sm=m,st=0;
        for(int i=n;i>=1;i--){
            if(a[i]<=p){
                if(p-a[i]<=sm) sm-=p-a[i],st++;
                else break;
            }
        }
        t=max(t,st);
    }
    cout<<t;
    return 0;
}
