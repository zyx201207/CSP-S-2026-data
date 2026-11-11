#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000000],ans,cnt,pos;
int main(){
    freopen("and.in","r",stdin);freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    for(int i=30;i>=0;i--){
        cnt=0;
        for(int j=0;j<n;j++){
            if(a[j]/(1<<i)%2)cnt++;
        }if(cnt>=m){
            ans+=(1<<i);pos=0;
            for(int j=0;j<n;j++){
                if(a[j]/(1<<i)%2){
                    a[pos++]=a[j];
                }
            }n=cnt;
        }
    }cout<<ans;
    return 0;
}