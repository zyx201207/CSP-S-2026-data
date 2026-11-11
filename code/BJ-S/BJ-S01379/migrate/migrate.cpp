#include<iostream>
#define ll long long
using namespace std;
ll c,t,arr[2000020],n,d,k,cc,cnt;
int main(){
    cin>>c>>t;
    //if(c == 11 || c == 12){
        while(t--){
            cin>>n>>d;
            for(int i = 1;i <= n;i++){
                cin>>arr[i];
            }
            if(n == 1){
                cout<<0;
                continue;
            }
            k = arr[2] - arr[1];
            cc = d / k;
            if(cc <= 1){
                cout<<0;
                continue;
            }
            cnt = cc + 2;
            if(cnt >= n){
                cout<<0;
                continue;
            }
            cout<<n - cnt + 1;
        }
    //}
    /*
    else{
        while(t--){
            cin>>n>>d;
            for(int i = 1;i <= n;i++){
                cin>>arr[i];
            }
            if(n == 1){
                cout<<0;
                continue;
            }

        }
    }
    */
    return 0;
}
