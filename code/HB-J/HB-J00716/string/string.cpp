#include<bits/stdc++.h>
using namespace std;
struct box{
    int x;
    char y;
}a[200005];
struct box1{
    int x;
    char y;
}b[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,s=0,c=0,sum=0,t;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].x>>a[i].y;
        s+=a[i].x;
        b[i].x=b[i-1].x+a[i].x;
        b[i].y=a[i].y;
    }
    s=s/2+1;
    for(int i=1;i<=n;i++){
            c+=a[i].x;
            t=0;
        if(c<=s){
            int k=c+s;
            bool v=0;
            for(int j=n;j>=1;j--){
                if(b[j].x<k){
                    if(b[j+1].y==a[i].y)v=1;
                    t=b[j+1].x-b[j].x;
                    if(t<a[i].x)t=a[i].x;
                    break;
                }
            }
            if(!v)sum+=t;
        }
        else {
            cout<<sum;
            return 0;
        }
    }
    return 0;
}
