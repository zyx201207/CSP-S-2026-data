#include <bits/stdc++.h>
using namespace std;
int n;
struct node{
    long long a;
    char c;
}arr[200005];
long long ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i].a>>arr[i].c;
    }
/*
    for(int i=1;i<=n;i++){
        cout<<arr[i].a<<arr[i].c;
    }
*/
    long long x=arr[1].a,y=arr[n].a;
    int xx=1,yy=n;
    while(1){

//        cout<<x<<' '<<y<<endl;

        if(x>y){
            if(arr[xx].c!=arr[yy].c){
                ans=ans+y;
            }
            x=x-y,y=0;
        }
        else if(x<y){
            if(arr[xx].c!=arr[yy].c){
                ans=ans+x;
            }
            y=y-x,x=0;
        }
        else{
            if(arr[xx].c!=arr[yy].c){
                ans=ans+x;
            }
            x=0,y=0;
        }
        if(x==0){
            xx++;
            x=arr[xx].a;
        }
        if(y==0){
            yy--;
            y=arr[yy].a;
        }
        if(xx>=yy){
            break;
        }

//      cout<<ans<<endl;

    }
    cout<<ans;
    return 0;
}
