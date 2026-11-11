#include<algorithm>
#include<iostream>
#include<fstream>
#include<cmath>
#include<string>
using namespace std;
long long n,m,a[200005],ans=0;
bool b[200005]={0};
int andd(int x,int y){
    int ans=0,cntx=1,cnty=1;
    bool xx[35],yy[35];
    while(x!=0||x!=1){
        xx[cntx]=x%2;
        x/=2;
        cntx++;
    }
    while(y!=0||y!=1){
        xx[cnty]=y%2;
        y/=2;
        cnty++;
    }
    int cntz=max(cntx,cnty);
    for(int i=1;i<=max(cntx,cnty);i++){
        if(xx[i]&&yy[i]){
            ans+=2*cntz;
        }
        cntz--;
    }
    return ans;
}
int main(){
    freopen("and.in","r","stdin");
    freopen("ans.out","w","stdout");
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=m;i++){
        for(int j=1,cnt=1,mmin=0;j<=n;j++){
            if(b[j]==1){
                continue;
            }
            if(andd(a[j],cnt)>cnt){
                cnt=andd(a[j],cnt);
            }
            else if(andd(a[j],cnt)>mmin){
                mmin=andd(a[j],cnt);
            }
            if(j==n){
                if(cnt>ans){
                    ans=cnt;
                }
                else{
                    ans=mmin;
                }
            }
        }
    }
    cout<<ans;

    return 0;
}
