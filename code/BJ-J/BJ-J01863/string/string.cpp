#include<iostream>
#include<cstdio>
using namespace std;
#define int long long
char c[200001];
int a[200001];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    int l=0,r=n+1;
    int b=-1,b1;
    int ans=0;
    while(true){
        if(b==-1){
            l++;
            r--;
            if(l>=r)break;
            b1=abs(a[l]-a[r]);
            if(c[l]!=c[r]){
                ans+=min(a[l],a[r]);
            }
            if(a[l]>a[r]){
                b=0;
            }
            else if(a[l]==a[r]){
                b=-1;
            }
            else{
                b=1;
            }
        }
        else if(b==0){//le
            r--;
            if(l==r)break;
            if(c[r]!=c[l]){
                ans+=min(a[r],b1);
            }
            if(b1==a[r]){
                b=-1;
                b1=0;
            }
            else if(b1>a[r]){
                b=0;
                b1=b1-a[r];
            }
            else{
                b=1;
                b1=a[r]-b1;
            }
        }
        else{
            l++;
            if(l==r)break;
            if(c[r]!=c[l]){
                ans+=min(a[l],b1);
            }
            if(b1==a[l]){
                b=-1;
                b1=0;
            }
            else if(b1>a[l]){
                b=1;
                b1=b1-a[l];
            }
            else{
                b=0;
                b1=a[l]-b1;
            }
        }
    }
    cout<<ans;
}
