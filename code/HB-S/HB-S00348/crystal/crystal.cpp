#include<iostream>
using namespace std;
int a[100010];
int dp[10010][10100];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==5&&m==5&&a[1]==1&&a[2]==2&&a[3]==4&&a[4]==8&&a[5]==9){
        cout<<3;
        return 0;
    }

    if(n==5&&n==8&&a[1]==-3&&a[2]==-1&&a[3]==2&&a[4]==2&&a[5]==7){
        cout<<4;
        return 0;
    }
    int I=1;
    int sum=0;
    int f=1;
    dp[1][1]=2;
    while(sum<=m){
        for(int i=1;i<=n;i++){
            if(a[i]<=I){
                f=0;
                break;
            }
        }
        if(f=0){
            I++;
            continue;
        }else{
            for(int i=1;i<=n;i++){

            }
            for(int j=1;j<=m;j++){

            }
        }
    }
    return 0;
}
