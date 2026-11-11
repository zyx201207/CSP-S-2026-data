#define fastio ios::sync_with_stdio(0);cin.tie(0);
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf=1e18;
const int maxn=2e6+35;

int n;
ll d;
ll a[maxn];
void input(){
    cin>>n>>d;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
}

int jumpfar[maxn];
void calc_jumpfar(){
    for(int i=1;i<=n;++i){
        ll tow=a[i]+d;
        int pos=upper_bound(a+1,a+n+1,tow)-a;
        jumpfar[i]=pos-1;
         // cout<<jumpfar[i]<<" ";
    }
     // cout<<endl;
}


ll ans=0;

namespace SOLVE1{
    void solve(){
        calc_jumpfar();
        for(int i=1;i<=n;++i){
            int nowpos=i;
            bool pre1=0,pre2=0;
            bool dirty=0;
            bool pre1dirty=0;
            ll tot=0;
            while(1){
                int l=nowpos;
                int r=jumpfar[nowpos];
                if(l==r) break;
                
                int pre1r=-1,pre2r=-1;
                if(pre1){
                    pre1r=jumpfar[nowpos-1];
                    if(pre1r<=l) pre1=0;
                }
                if(pre2){
                    pre2r=jumpfar[nowpos-2];
                    if(pre2r<=l) pre2=0;
                }
				
				if(!dirty){
	                if(pre1&&!pre1dirty){
	                	ll pretot=tot;
	                    if(!pre2) tot+=pre1r-l;
	                    else tot+=pre1r-pre2r;
	                     // cout<<"ok "<<pre1r-(tot-pretot)+1<<" "<<pre1r<<endl;
	                }
				}
				else{
	                ll pretot=tot;
					if(!pre1) tot+=r-l;
					else tot+=r-pre1r;
	                 // cout<<"ok "<<r-(tot-pretot)+1<<" "<<r<<endl;
				}

				if(pre1r==r){
					if(dirty) break;
					dirty=1;
				}
				if(pre2r==r) break;
                if(r-l>=2){
                    if(pre1&&pre1r>=r-1) pre1dirty=1;
                    pre1=1;
                } 
                else pre1=0;
                if(r-l>=3) pre2=1;
                else pre2=0;
                nowpos=r;
            }
            ans+=tot;
             // cout<<ans<<"\n";
        }
        printf("%lld\n",ans);
    }
}


namespace SOLVE2{
    ll dp[maxn][3][2][2];
    void calc_dp(int nowpos,int x,int y,int z){
        int l=nowpos;
        int r=jumpfar[nowpos];
        if(l==r){
            dp[nowpos][x][y][z]=0;
            return;
        }

        int pre1,pre2,dirty;
        int pre1dirty=0;
        if(x>=1){pre1=1;}
        else{pre1=0;}
        if(x>=2){pre2=1;}
        else{pre2=0;}
        dirty=y;
        pre1dirty=z;

        
        ll tot=0;

        int pre1r=-1,pre2r=-1;
        if(pre1){
            pre1r=jumpfar[nowpos-1];
            if(pre1r<=l) pre1=0;
        }
        if(pre2){
            pre2r=jumpfar[nowpos-2];
            if(pre2r<=l) pre2=0;
        }
        
        if(!dirty){
            if(pre1&&!pre1dirty){
                ll pretot=tot;
                if(!pre2) tot+=pre1r-l;
                else tot+=pre1r-pre2r;
                // // cout<<"ok "<<pre1r-(tot-pretot)+1<<" "<<pre1r<<endl;
            }
        }
        else{
            ll pretot=tot;
            if(!pre1) tot+=r-l;
            else tot+=r-pre1r;
            // // cout<<"ok "<<r-(tot-pretot)+1<<" "<<r<<endl;
        }

        dp[nowpos][x][y][z]+=tot;

        if(pre1r==r){
            if(dirty) return;
            dirty=1;
        }
        if(pre2r==r) return;
        if(r-l>=2){
            if(pre1&&pre1r>=r-1) pre1dirty=1;
            pre1=1;
        } 
        else pre1=0;
        if(r-l>=3) pre2=1;
        else pre2=0;

        int fromx=0,fromy=0;
        if(pre1) fromx++;
        if(pre2) fromx++;
        fromy=dirty;

        dp[nowpos][x][y][z]+=dp[r][fromx][fromy][pre1dirty];
    }

    void reset(){
        for(int i=n;i>=1;--i){
            for(int x=0;x<=2;++x){
                for(int y=0;y<=1;++y){
                    for(int z=0;z<=1;++z){
                        dp[i][x][y][z]=0;
                    }
                }
            }
        }
    }
    void solve(){
    	calc_jumpfar();
        for(int i=n;i>=1;--i){
            for(int x=0;x<=2;++x){
                for(int y=0;y<=1;++y){
                    for(int z=0;z<=1;++z){
                        calc_dp(i,x,y,z);
                    }
                }
            }
            ans+=dp[i][0][0][0];
        }
        printf("%lld\n",ans);
        reset();
    }
}

void reset(){
    memset(jumpfar,0,sizeof(jumpfar[0])*(n+5));
    ans=0;
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
    fastio;
    int ccc,T;
    cin>>ccc>>T;
    while(T--){
        input();
        if(ccc<=10) SOLVE1::solve();
        else SOLVE2::solve();
        reset();
    }
    return 0;
}
