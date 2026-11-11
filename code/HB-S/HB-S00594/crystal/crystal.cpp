#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long n,m;
int find1(long long avg){
    int l=1,r=n;
    long long mid;
    while(l+1<r){
        long long x=a[l],y=a[r];
        mid=(l+r)/2;
        long long z=a[mid];
        if(z<avg)l=mid;
        else r=mid;
    }
    return l;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    long long min1=1e12,max1=-1e12;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        min1=min(min1,a[i]);
        max1=max(max1,a[i]);
    }
    if(min1==max1){
        cout<<n<<endl;
        return 0;
    }
    sort(a+1,a+n+1);
    long long avg=(min1+max1)/2+1;
    int mid=find1(avg);
    long long mn;
    if(a[mid]>avg)mid--;
    mn=a[mid];
    //cout<<mid<<endl;
    //cout<<mn<<endl;
    //cout<<endl;
    int sum=0;
    for(int i=mid;i>0;i--){
        long long z=mn-a[i];
        if(m-z>=0){
            m-=z;
            sum++;
        }
        else break;
    }
    cout<<sum<<endl;
    return 0;
}
