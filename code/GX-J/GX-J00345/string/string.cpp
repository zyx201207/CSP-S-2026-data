#include<bits/stdc++.h>
using namespace std;
int a[100005];
char b[100005];
long long c[100005];
long long ans=0;
long long cnt=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        scanf("%d",&a[i]);
        cnt+=a[i];
        cin>>b[i];
        c[i]=cnt;
    }
    int j=n-1;
    long long cnt2=0;
    //long long lll=cnt;
    for(int i=0;i<n;++i){
        cnt2=c[i];
        if(cnt2>cnt/2)cnt2=cnt/2;
        //cout<<c[j]<<'-'<<cnt<<'-'<<cnt2<<"\n";
        for(;j>=0&&c[j]>=cnt-cnt2;--j){
            if(b[j]!=b[i]){
                if(c[j]-a[j]<cnt-cnt2&&b[i+1]==b[j])ans+=c[j]+cnt2-cnt;
                else ans+=a[j];
                //if(lll<=c[j])ans-=c[j]-lll;
            }
            //lll=cnt2;
            //cout<<i<<' '<<j<<' '<<ans<<"\n";
        }
        if(c[i]>cnt/2)break;
    }
    if(ans>cnt/2)ans=cnt/2;
    cout<<ans;
    return 0;
}
