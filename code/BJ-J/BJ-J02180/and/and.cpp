#include<iostream>
#include<algorithm>
using namespace std;
int n,m;
int a[200007];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(m==1){
        cout<<n;
        return 0;
    }
    if(m==2){
        for(int i=n;i>=1;i--){
            if(a[i]==a[i-1]){
                cout<<a[i];break;
            }
        }
    }
    else if(m==n){
        int ans=a[n];
        for(int i=n;i>=1;i--){
            ans&=a[i];
        }
        cout<<ans;
    }
    else{
        cout<<a[n-m+1];
    }
    return 0;
}
/*
• 两张车票对应的座位是否在同一节车厢;
• 两张车票对应的座位是否在同一节车厢的同一排;
• 两张车票对应的座位是否在同一节车厢的同一排,且位于过道的同一侧;
• 两张车票对应的座位是否相邻。
*/
