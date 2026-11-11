#include<bits/stdc++.h>
using namespace std;
struct duan{
    long long start,end;
    char w;
}d[200005];
long long n,sum=1,ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        long long x;cin>>x>>d[i].w;
        d[i].start=sum;
        sum+=x;
        d[i].end=sum-1;
    }

    long long l=1,r=sum-1,li=1,ri=n;
    while(l<r&&li<=ri){
        long long x1=d[li].end-l+1,x2=r-d[ri].start+1;
        long long x=min(x1,x2);
        if(d[li].w!=d[ri].w) ans+=x;
        l+=x;
        r-=x;
        if(l>d[li].end) li++;
        if(r<d[ri].start) ri--;

    }
    cout<<ans;
}