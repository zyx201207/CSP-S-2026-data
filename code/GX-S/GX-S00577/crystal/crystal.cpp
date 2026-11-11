#include<bits/stdc++.h>
using namespace std;
int n;
long long int m;
int arr[500005]={0};
bool x(int a,int b){
    return a<b;
}
long long int dp=0;
int maxx=0;
long long int k=0;
int ji=0;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    sort(arr+1,arr+n+1,x);
    maxx=0;
    k=0;
    ji=0;
    for(int i=n-1;i>=1;i--){
        maxx=max(ji,maxx);
        k=0;
        ji=0;
        for(int j=i;j>=1;j--){
            dp=arr[i+1]-arr[j];
            if(k+dp<=m){
                k+=dp;
                ji++;
                continue;
            }
            break;
        }
    }
    maxx=max(maxx,ji);
    cout<<maxx+1;
    return 0;
}
