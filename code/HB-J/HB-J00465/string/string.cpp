#include<bits/stdc++.h>
using namespace std;
long long n,i,ans=0;
long long a[200010];
char c[200010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a[i]>>c[i];
    }
    int h=0,t=n-1;
    while(h<=t){
        if(a[h]>a[t]){
            if(c[h]==c[t]){
                a[h]-=a[t];
                t--;
            }
            else{
                ans+=a[t];
                a[h]-=a[t];
                t--;
            }
        }
        else if(a[h]<a[t]){
            if(c[h]==c[t]){
                a[t]-=a[h];
                h++;
            }
            else{
                ans+=a[h];
                a[t]-=a[h];
                h++;
            }
        }
        else if(a[h]==a[t]){
            if(c[h]==c[t]){
                h++;
                t--;
            }
            else{
                ans+=a[h];
                h++;
                t--;
            }
        }
    }
    cout<<ans;
    return 0;
}
