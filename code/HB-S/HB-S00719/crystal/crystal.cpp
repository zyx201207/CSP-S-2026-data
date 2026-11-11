#include<bits/stdc++.h>//rp=rp+INT_MAX
using namespace std;
long long n,m,a[1000010],t=INT_MAX,ttt,ans[1000010],rp=0;
struct m{
    long long p;
    long long q;
    long long cha;
}b[1000010];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    //if(i==0)cout<<1<<" ";
    //else if(i==1)cout<<1<<" ";
    //else if(i==2)cout<<2<<" ";
    //else if(i==3)cout<<0<<" ";
    //else if(i==4)cout<<0<<" ";
    //else if(i==5)cout<<1<<" ";
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    if(n%2==0)ttt=a[(n+1)/2];
    else ttt=a[(n+1)/2-1];
    for(int i=0;i<n;i++){
        ans[i]=abs(ttt-a[i]);
    }
    sort(ans,ans+n);
    for(int i=0;i<n;i++){
        if(m-ans[i]>=0&&ans[i]>=0){
        m=m-ans[i];
        rp++;
    }
        else{
            break;
        }
    }
    cout<<rp;
    return 0;
}
