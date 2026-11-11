#include<iostream>
using namespace std;
#define int unsigned long long
const int N=2e5+5;
int a[N];
char c[N];

signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    int sum=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum+=a[i];
        cin>>c[i];
    }
    int onesize=0,twosize=0,ans=0,oneid=1,twoid=n,nextone=0,nexttwo=0;
    sum/=2;
    while(1){
        if(onesize+twosize>=sum*2){
            break;
        }
        if(onesize<=twosize){
            nextone=onesize;
            if(onesize+a[oneid]>sum){
                onesize+=sum-onesize;
            }else{
                onesize+=a[oneid];
            }
            oneid++;
            if(onesize<twosize){
                if(c[twoid+1]!=c[oneid-1]){
                    ans+=onesize-nextone;
                }
            }else{
                if(c[twoid+1]!=c[oneid-1]){
                    ans+=twosize-nextone;
                }
            }
        }else{
            nexttwo=twosize;
            if(twosize+a[twoid]>sum){
                twosize+=sum-twosize;
            }else{
                twosize+=a[twoid];
            }
            twoid--;
            if(twosize<onesize){
                if(c[twoid+1]!=c[oneid-1]){
                    ans+=twosize-nexttwo;
                }
            }else{
                if(c[twoid+1]!=c[oneid-1]){
                    ans+=onesize-nexttwo;
                }

            }
        }
    }
    cout<<ans<<'\n';
}