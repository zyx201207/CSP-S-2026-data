//GZ-J00505 贵阳市第三实验中学 郑傅允
#include <bits/stdc++.h>
using namespace std;
bool cmp(long long x,long long y){
    return x>y;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long a,b,c[200000]={};
    cin>>a>>b;
    for(long long i=0;i<a;i++) cin>>c[i];
    sort(c,c+a,cmp);
    long long ans=c[0];
    for(long long j=1;j<b;j++) ans=ans&c[j];
    cout<<ans;
    return 0;
}
