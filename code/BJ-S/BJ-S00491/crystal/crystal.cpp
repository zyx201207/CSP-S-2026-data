#include<bits/stdc++.h>
using namespace std;
const N=1e5*5+8;
bool d[N];
int a[N];
int main(){
    int minn=9999999,p=0,q=0;
    freopen("crystal.in",r,stdin);
    freopen("crystal.out",w,stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    while(m>0){
        for(int i=1;i<=1000000;i++){
            for(int j=1;j<=n;j++){
                if((a[i+1]-a[i])<minn&&!d[i]){
                    minn=a[i+1]-a[i];
                    p=i;
                }
            }
        }
        if(m>=minn){
            a[p]+=minn;
            m-=minn;
            d[p]=true;
            q++;
        }else{
            break;
        }
    }
    cout<<q;
    return 0;
}
