#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","m",stdout);
    int n=0,m=0;
    cin >>n>>m;
    int arr[500001]={0};
    for(int i=0;i<n;i++){
        cin >>arr[i];
    }
    int sum[n+1]={0};
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(sum[i]!=arr[j]){
                sum[i]=arr[j];
            }else{
                for(int k=arr[k];k<n;k++){
                    sum[k]=0;
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        cout <<sum[i]<<" ";
    }
    return 0;
}
