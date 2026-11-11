#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],a2[200005],maxx=0,p=1,cnt=0,q[25],sum[25],ans[200005],st,con=0,answer=0;
bool x[25][2100000],f;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a2[i]=a[i];
        maxx=max(maxx,a[i]);
    }
    q[0]=1;
    while(p*2<=maxx){
        p*=2;
        ++cnt;
        q[cnt]=p;
    }
    for(int i=cnt;i>=0;i--){
        for(int j=1;j<=n;j++){
            if(a2[j]>=q[i]){
                x[i][a[j]]=true;
                a2[j]-=q[i];
                ++sum[i];
            }
        }
    }
    sort(a+1,a+n+1);
    for(int i=cnt;i>=0;i--){
        if(sum[i]>=m){
            for(int j=n;j>=1;j--){
                if(x[i][a[j]]&&con+1<=m){
                    ++con;
                    ans[con]=a[j];
                }
            }
            st=i;
            break;
        }
    }
    for(int i=st;i>=0;i--){
        f=1;
        for(int j=1;j<=con;j++){
            if(!x[i][ans[j]]){
                f=0;
                break;

            }
        }
        if(f){
            answer+=q[i];
        }
    }
    cout<<answer;
    return 0;
}
