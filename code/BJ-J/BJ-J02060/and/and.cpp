#include<bits/stdc++.h>
using namespace std;
int n,a[1010],sss1[1010],sss2[1010],m,maxx=-1,ss1,ss2;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","r",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int s111=i;
            int s222=j;
            int aaaa=0;
            while(s111>0){
                aaaa++;
                sss1[aaaa]=s111%2;
                s111/=2
            }
            aaaa=0;
            while(s222>0){
                aaaa++;
                sss2[aaaa]=s222%2;
                s222/=2
            }
            int z=0;
            for(int i=aaaa;i>=1){
                z++;
                ss1 +=sss1[i]*pow(10,z);
            }
            z=0;
            for(int i=aaaa;i>=1){
                z++;
                ss1 +=sss1[i]*pow(10,z);
            }
            if(ss1+ss2>maxx){
                maxx=ss1+ss2;
            }
        }
    }
    cout<<maxx;
    return 0;
}
