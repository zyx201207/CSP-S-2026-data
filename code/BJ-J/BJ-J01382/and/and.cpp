#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200010],f[200001],l[200001];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        f[i]=a[i];
    }
    int fl=n,r=0;
    for(int i=31;i>=0;i--){
        int x=0;
        for(int j=1;j<=fl;j++){
            if((f[j])&(1<<i)){
                x++;
                l[x]=f[j];
            }
        }
/*
        cout<<i<<' '<<x<<endl;
        for(int j=1;j<=x;j++){
            cout<<l[j]<<' ';
        }
        cout<<endl;
*/
        if(x>=m){
            fl=x;
            r=(r|(1<<i));
            for(int j=1;j<=x;j++)
                f[j]=l[j];
        }
    }
    cout<<r<<endl;
    return 0;
}
