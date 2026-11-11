// redirected? yes
// undebugged? yes

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<array>
#include<functional>
using namespace std;

//#define debug // redirected when off

const size_t MAXN=2e5+3,MAXM=MAXN;
int a[MAXN];

int getBits(int x){
    int cnt=0;
    while(x){
        x>>=1;
        ++cnt;
    }
    return cnt;
}

int main(){
    #ifndef debug
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #endif // debug
    freopen("and.in","r",stdin);

    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }

    //case 6
    if(m==1){
        cout<<*max_element(a+1,a+n+1)<<'\n';
    }
    //case 7
    else if(m==n){
        int res=a[1];
        for(int i=2;i<=n;++i)res&=a[i];
        cout<<res<<'\n';
    }
    //case 8-10
    else if(m==2){
        int res=-0x3f3f3f3f;
        for(int i=1;i<=n;++i){
            for(int j=i+1;j<=n;++j){
                int andSum=a[i]&a[j];
                res=max(res,andSum);
            }
        }
        cout<<res<<'\n';
    }
    //case 1-5
    else if(n<=20){
        int res=-0x3f3f3f3f;

        array<bool,23> usedIdx;
        function<void(int,int)> dfs=[&](int choseCnt,int startFrom){

            if(choseCnt==m){
                int andSum=(1ll<<22);
                for(int i=1;i<=n;++i){
                    if(usedIdx[i]){
                        andSum&=a[usedIdx[i]];
                    }
                }
                res=max(res,andSum);
                return;
            }

            for(int i=startFrom;i<=n;++i){
                if(usedIdx[i])continue;

                usedIdx[i]=true;
                dfs(choseCnt+1,i);
                usedIdx[i]=false;
            }
        };

        dfs(0,1);

        cout<<res<<'\n';
    }
    // case 11-12
//    else if(m==n-1){
//        for(int )
//    }

    return 0;
}
