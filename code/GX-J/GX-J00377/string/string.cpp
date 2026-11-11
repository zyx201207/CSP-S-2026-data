#include<bits/stdc++.h>

using namespace std;
long long rund,turn,temp,now,ans;
long long b[100000000];
char a;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>rund;
    for (int i=0;i<rund;i++){

        cin>>turn>>a;
        now+=turn;
        temp=a;
        for (int k=i;k<=turn+i;k++)
            b[k]=a;

    }


    if(now%2==0){
        for(int i=0;i<=now/2;i++){
            if(b[i]!=b[now-i-1]){
                ans++;
            }
        }
    }else{
        for(int i=0;i<=now/2;i++){
            if(b[i]!=b[now-i-1]){
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}
