#include<iostream>
#include<algorithm>
using namespace std;

bool cmp(int x,int y){
    return x>y;
}

int main(){
    freopen("ctystal4.in","r",stdin);
    freopen("ctystal.out","w",stdout);

    int a[50010];
    int n;
    int m;
    cin>>n>>m;
    int sum[50010];
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=1;
    }
    sort(a,a+n+1);
    int  u=m;
    for(int i=2;i<=n;i++){
        for(int j=i-1;j>=1;j--){
            if(a[i]-a[j]<=u){
                sum[i]+=1;
                m-=a[i]-a[j];
            }
        }
    }
    sort(sum,sum+n+1,cmp);
    cout<<sum[1];

return 0;
}
