#include<bits/stdc++.h>
using namespace std;
int n;
int m;
int a[200010];
int abc[200010];
int sum;
int Msum;
void xuan(int x,int l){
    if(x==0)return;
    if(x==1){
        for(int i=l;i<=n;i++){
            abc[m-x+1]=a[i];
            for(int j=1;j<=m;j++){
                sum=sum&abc[j];
            }
            Msum=max(sum,Msum);
        }

    }
    for(int i=l;i<=n-x+1;i++){
        abc[m-x+1]=a[i];
        xuan(x-1,i+1);
        sum=abc[1];

    }
    return;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n-m;i++){
        abc[1]=a[i];
        xuan(m-1,i+1);
    }
    cout<<Msum;
    return 0;
}
