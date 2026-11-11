#include<bits/stdc++.h>
using namespace std;
const int N=200010;
struct S{
    long long x;
    char y;
}a[N];
int n;
long long ans=0ll;
int i,j;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i].x>>a[i].y;
    }
    i=0;j=n-1;
    while(i<j){
        if(a[i].y==a[j].y){
            if(a[i].x>a[j].x){
                a[i].x=a[i].x-a[j].x;
                j--;
            }
            else if(a[i].x<a[j].x){
                a[j].x=a[j].x-a[i].x;
                i++;
            }
            else{
                i++;
                j--;
            }
        }
        else{
            if(a[i].x>a[j].x){
                a[i].x=a[i].x-a[j].x;
                ans=ans+(long long)a[j].x;
                j--;
            }
            else if(a[i].x<a[j].x){
                a[j].x=a[j].x-a[i].x;
                ans=ans+(long long)a[i].x;
                i++;
            }
            else {
                ans=ans+(long long)a[j].x;
                i++;
                j--;
            }
        }
    }
    cout<<ans;
    return 0;
}
