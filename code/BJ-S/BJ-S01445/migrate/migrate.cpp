#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,t;
int a[2000005];
int f[15][15];

int dfs(int step,int l,int r){
    //cout<<step<<" "<<l<<" "<<r<<endl;
    int ret; ret=0;
    if(step==0){
        if(l==r){
            return 1;
        }
        else{
            return 0;
        }
    }

    for(int i=l+1;i<=r;i++){
        if(a[i]-a[l]<=t){
            ret+=dfs(step-1,i,r);
        }
    }

    return ret;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    int c,_; cin>>c>>_;

    while(_--){
        cin>>n>>t;

        for(int i=1;i<=n;i++){
            cin>>a[i];
        }

        if(c==11 || c==12){
            int d; d=a[n]-a[n-1];
            int L; L=(t/d)*2;
            //cout<<d<<" "<<t<<" "<<L<<endl;
            if(L<=2){
                cout<<0<<endl;
            }
            else{
                cout<<max(0ll,n-L+1)<<endl;
            }
        }
        else{
            int ans; ans=0;
            for(int i=1;i<=n;i++){
                for(int j=i+2;j<=n;j++){
                    for(int k=1;k<=j-i;k++){
                        //cout<<k<<": \n";
                        int tmp; tmp=dfs(k,i,j);
                        //cout<<k<<" "<<i<<" "<<j<<" "<<tmp<<endl;
                        if(tmp==2){
                            ans++;
                            break;
                        }
                        else if(tmp){
                            break;
                        }
                    }
                }
            }

            cout<<ans<<endl;
        }
    }
    return 0;
}

/*
Est Score: 16

Est Total Score:[176,216]
im so vegetable
but i think i can get 1=
actually idc bc im senior high
not 0 is just fine
last year of oi i just need 1= on noip
i got 1= on noip2025 but i was junior 3..

im so tired
just 3 days until mid-term
after the mid-term i still have to work on a rhythm game project
..if anyone's reading this and want to join Project "Lynavia"
you can contact me through luogu635361

oh right why doesn't the recycling system let me use chinese
it pops out an error
so i cant use chinese to write this text

i want to play Arcaea..
how did you know that i got Parallax ETR11.3 PM(-69) on 10.29

looking through this why do i think i sound like Monika(ddlc)..
speaking of visual novels,
i still havent finished Tsukiniyourisou and Otomeiron yet..
Sakurakouji Luna saikyo

well
wish me good luck on my midterm ig
*/
