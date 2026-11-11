//Today's csp-s2 is too diffcult!
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,m,a[500005],cha[500005],ans=1;
char nt,mt;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    sort(a+1,a+1+n);

    if(m==0){
        ll tmp=1;
        for(int i=1;i<=n;++i){
            if(a[i]==a[i-1])
                tmp++;
            else{
                ans=max(tmp,ans);
                tmp=1;
            }
        }
        cout<<ans;
        return 0;
    }

    int minn=a[1],maxx=a[n];
    if(minn>maxx){
        int ling=minn;
        minn=maxx;
        maxx=ling;
    }
    for(int i=minn;i<=maxx;++i){        //range
        for(int j=1;j<=n;++j){          //start point
            if(a[j]>=i)
                break;
            int need=0;
            for(int k=j;k<=n;++k){      //start range
                int tmp=abs(i-a[k]);
                if(need+tmp<=m)
                    need+=tmp;
                else{
                    ans=max(ans,(ll)k-j);
                    break;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}

