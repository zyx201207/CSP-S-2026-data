#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,L;
const int N=2e5+5;
int a[N];
char c[N];
int sum[N];
int ans=0;
int l=1,r=n;
void solve1(){
    if(a[l]==a[r]){
        a[l]=a[r]=0;
    }else if(a[l]>a[r]){
        a[l]-=a[r];
        a[r]=0;
    }else if(a[l]<a[r]){
        a[r]-=a[l];
        a[l]=0;
    }
}

void solve2(){
    if(a[l]==a[r]){
        //cout<<"a"<<endl;
        ans+=a[l];
        a[l]=a[r]=0;
    }else if(a[l]>a[r]){
        //cout<<"b"<<endl;
        ans+=a[r];
        a[l]-=a[r];
        a[r]=0;
    }else if(a[l]<a[r]){
        //cout<<"c"<<endl;
        ans+=a[l];
        a[r]-=a[l];
        a[l]=0;
    }
}

signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        sum[i]=sum[i-1]+a[i];
        L+=a[i];
    }
    r=n;
    //cout<<r<<" "<<a[r]<<endl;
    do{
            //cout<<a[l]<<" "<<a[r]<<endl;
        if(c[l]==c[r]){
            solve1();
            //cout<<1<<endl;
        }else{
            solve2();
            //cout<<2<<endl;
        }
        //cout<<ans<<endl;
        if(a[l]==0)l++;
        if(a[r]==0)r--;
        //puts("");
    }while(l<r);
    cout<<ans;
    return 0;
}
/*
int ans=0;
    for(int i=1;i*2<=L;i++){
        int j=L+1-i;
        int x=lower_bound(sum+1,sum+n+1,i)-sum;
        int y=lower_bound(sum+1,sum+n+1,j)-sum;
        if(c[x]!=c[y]){
            ans++;
        }
    }
    cout<<ans;
*/
