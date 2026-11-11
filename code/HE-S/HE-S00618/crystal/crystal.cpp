#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    long long da=1000000;
    long long dacha;
    long long xiao=-1000000;
    long long xiaocha;
    long long zhencha;
    long long pg=0;
    long long ans=0;
    cin>>n>>m;
    int arr[500000];
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    if(m!=0){
        for(int i=1;i<=n;i++){
            pg+=arr[i];
        }
        pg/=n;
        for(int i=1;i<=n;i++){
            if(arr[i]>=pg && arr[i]<=da){
                da=arr[i];
                break;
            }
        }
        dacha=da-pg;
        for(int i=n;i<=1;i--){
            if(arr[i]<=pg && arr[i]>=xiao){
                xiao=arr[i];
                break;
            }
        }
        xiaocha=pg-xiao;
        if(xiaocha>dacha){
            pg=da;
        }
        if(dacha>xiaocha){
            pg=xiao;
        }else{
            pg=xiao;
        }
        for(int i=m;i>=1;i--){
            if(arr[i]<pg){
                arr[i]+=1;
            }
        }
        for(int i=1;i<=n;i++){
            if(arr[i]==pg){
                ans++;
            }
        }
}
    cout<<ans<<endl;
    fclose(stdin);
    fclose(stdout);
}
