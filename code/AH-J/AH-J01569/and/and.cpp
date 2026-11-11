#include<bits/stdc++.h>
using namespace std;
const int N=20010;
int a[N];
int d[N][N];
bool cmp(const int &x,int &y){
    return x>y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;

    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n,cmp);
    if(m==1){
        cout<<a[1];
        return 0;
    }
    for(int i=1;i<=n;i++){
        d[i][1]=a[1];
    }
   for(int i=2;i<=n;i++){
        for(int j=2;j<=i;j++){
            int maxn=0,p=0;
            for(int k=1;k<i;k++){
                int c=d[k][j-1]&a[i];
                if(c>maxn){
                    maxn=d[k][j-1]&a[i];
                    p=k;
                }
            }
            d[i][j]=max(maxn,d[i-1][j]);
        }

    }
    cout<<d[n][m];
    return 0;
}
