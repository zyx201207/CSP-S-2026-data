#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5;
long long a[N],n,m;
long long getin(){
    long long rea=0;
    char t=getchar(),y;
    if(t!='-')rea=t-'0';
    while(1){
        y=getchar();
        if(y==' ')break;
        if(y=='\n')break;
        rea*=10;
        rea+=y-'0';
    }
    if(t=='-')return -rea;
    return rea;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%d",&n,&m);
    getchar();
    for(int i=0;i<n;i++)a[i]=getin();
    sort(a,a+n);
    long long ans=1,kar=0;
    for(;ans<n;ans++){
        if(a[ans]==a[ans-1])continue;
        if(m-kar<(a[ans]-a[ans-1])*ans)
        {
            //cout<<kar+(a[ans]-a[ans-1])*ans<<endl;
            break;
        }
        kar+=(a[ans]-a[ans-1])*ans;
        //cout<<kar<<endl;
    }
    cout<<ans;
    return 0;
}
