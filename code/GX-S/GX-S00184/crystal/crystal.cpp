#include<bits/stdc++.h>
using namespace std;

long long a[500010],b[500010],cnt=0,s=0;
long long n,m;

int cheak(int x){
    s=0;
    for(int i=0;i<n;i++){
        b[cnt++]=x-a[i];
    }
    for(int i=0;i<n;i++){
        if(b[i]<0) continue;
        else m-=b[i],s++;
    }
    return s;
}
int main(){
    //freopen("crystal.in","r",stdin);
    //freopen("crystal.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%ld",&a[i]);
    }
    sort(a,a+n);
    long long l=a[0],r=a[n-1],ans=0,mid,c;
    while(l<=r){
        mid=l+(r-l)/2;
        c=cheak(mid);
        if(c>ans) r--,ans=c;
        else l++;
    }
    cout<<ans;
    return 0;
}
