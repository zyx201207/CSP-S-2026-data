#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n;
long long m;
long long a[N],sum[N];
int id;
long long ans;
int maxsum=-1;
int hf(long long x,int i){
    int l=1,r=i;
    int mid;
    while(l<=r){
        mid=(l+r)/2;
        if(sum[mid]>x)r=mid-1;
        else if(sum[mid]<x)l=mid+1;
        else return mid;
    }
    return l;
}
long long ch;
bool cmp(long long x,long long y){
    return x<y;
}
int bol2=1;
int ch1;
int numoi;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++){
        if(i==2) ch1=a[2]-a[1];
        if(i>2){
            if(a[i]-a[i-1]!=ch1) bol2=0;
        }
    }
    if(bol2==1){
        numoi=m/ch1;
        int i=1;
        for(i=1;numoi-i>0;){
            numoi-=i;
            i++;
        }
        if(i>numoi)i--;
        cout<<min(i,n-1)+1;
    }
    else{
        ch=0-a[1];
        for(int i=1;i<=n;i++){
            a[i]=a[i]+ch;
        }
        for(int i=1;i<=n;i++){
            sum[i]=sum[i-1]+a[i];
        }
        for(int i=1;i<=n;i++){
            ans=a[i]*i-m;
            ans=ans-sum[i];
            ans*=2;
            if(sum[i]<ans) continue;
            else{
                id=hf(ans,i);
                maxsum=max(maxsum,i-id+1);
            }
        }
        cout<<maxsum;
    }
    return 0;
}
