#include<iostream>
#include<cmath>
using namespace std;
int n,m;
int a[200009];
int ans=0;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    int flag=0x7fffffff;
    for(int j=30;j>=0;j--){
        int cnt=0;
        int w=pow(2,j);
        for(int i=1;i<=n;i++){
            if((a[i]&flag)>=w)cnt++;
            else a[i]=0;
        }
        if(cnt>=m)ans+=w;
    }
    cout<<ans;
    return 0;
}