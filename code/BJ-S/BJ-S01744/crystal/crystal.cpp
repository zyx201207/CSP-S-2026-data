#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005],c[500005];
long long cnt=1;
long long ans=1;
bool cmp(long long l,long long r){
    return l>r;
}
bool isa=true,isb=true;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=i){
            isa=false;
        }
        if(i>=3){
            if((abs(a[i]-a[i-1]))!=(abs(a[i-1]-a[i-2]))){
                isb=false;
            }
        }
    }
    if(isa){
        for(long long i=2*sqrt(m);i>=1;i--){
            if(m > (((1+i)*i)/2)){
                cout<<i+2;
                return 0;
            }
        }
    }
    if(isb){
        for(long long i=2*sqrt(m);i>=1;i--){
            if(m > (((a[1]+a[n])*n)/2)){
                cout<<i+2;
                return 0;
            }
        }
    }
    sort(a+1,a+n+1,cmp);
    for(long long i=1;i<=n;i++){
        cnt=1;
        long long add=0;//相同的个数
        long long m1=m;
        //sort(c+1,c+cnt+1,cmp);
        for(long long j=i;j<=n;j++){
            if(m1<a[j]){
                break;
            }else{
                m1-=(a[i]-a[j]);
                add++;
                //cout<<m1<<' '<<add<<endl;
            }
            //cout<<"RUNNING..."<<endl;
        }
        ans=max(ans,add);
    }
    cout<<ans;
    return 0;
}
