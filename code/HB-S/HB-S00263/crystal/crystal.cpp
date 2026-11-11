#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    a[0]=-0x3f3f3f3f;
    long long l=n/2,r=n/2+1,num,cnt=0;
    if(n%2==0) num=(a[n/2]+a[n/2+1])/2;
    else num=a[n/2+1];
    while(m>0){
        if(num-a[l]<=a[r]-num){
            m-=num-a[l];
            a[l]=num;
            cnt++;
            l--;
        }
        else{
            m-=a[r]-num;
            num=a[r];
            cnt++;
            r++;
        }
    }
    if(m<0) cnt--;
    cout<<cnt<<endl;
    return 0;
}
