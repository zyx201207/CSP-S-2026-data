#include<bits/stdc++.h>
using namespace std;
long long  a[200005];
long long  maxn;
bool flag;
long long  now;
int main(){

    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    flag=true;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        maxn=max(a[i],maxn);
        if(a[i]!=(i-1)){
            flag=false;
        }
    }
    if(m==1){
        cout<<maxn;
        return 0;
    }
    if(flag){

        now=a[n];
        int p=n;
        int q=m;
        while(q--)
        {
            now&=a[p];
            p--;
        }




        cout<<now;
        return 0;

    }
    sort(a+1,a+1+n);
    now=a[n];
     int p=n;
        int q=m;
        while(q--)
        {
            now&=a[p];
            p--;
        }
    cout<<now;
    return 0;
}
