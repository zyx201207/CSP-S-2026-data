#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
long long m,m2,c[500000];
int n,ans=1,ans2;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;++i)cin>>c[i];
    sort(c,c+n);
    for(int i=n-1;i>0;--i){
        m2=m;
        ans2=1;
        for(int j=i-1;j>-1;--j){
            if(m2>=c[i]-c[j]){
                m2-=c[i]-c[j];
                ans2++;
            }
            else break;
        }
        ans=max(ans,ans2);
    }
    cout<<ans;
    return 0;
}
