#include<bits/stdc++.h>
using namespace std;
const int N = 1e4+10;
struct node{
    int neng;
}dp[N];
bool cmp(node x,node y){
    return x.neng<y.neng;

}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;cin>>n>>m;
    for(int i = 1;i<=n;i++){
        cin>>dp[i].neng;
    }
    sort(dp+1,dp+1+n,cmp);
    if(m==0){
        cout<<1<<endl;
    }
    while(n<=5){
        if(n==1){ cout<<1<<endl;continue;}
        else if(n==2){
            if(dp[2].neng-dp[1].neng>m){ cout<<1<<endl; continue;}
            else {cout<<2<<endl;}
        }
        else if(n==3){
            if(dp[3].neng - dp[2].neng > m){
                if(dp[2].neng - dp[1].neng > m){ cout<<1<<endl;continue;}
                else cout<<2<<endl;
            }
            else{
                if(dp[3].neng - dp[1].neng > m - (dp[3].neng - dp[2].neng)) cout<<2<<endl;
                else cout<<3<<endl;
            }
        }
        else if(n==4){
             if(dp[4].neng - dp[3].neng > m){
                if(dp[3].neng - dp[2].neng > m){
                    if(dp[2].neng - dp[1].neng > m) cout<<1<<endl;
                    else cout<<2<<endl;
                }
                else{
                    if(dp[2].neng-dp[1].neng > m-(dp[3].neng-dp[2].neng)) cout<<2<<endl;
                    else cout<<3<<endl;
                }
            }
            else{
                if(dp[3].neng-dp[2].neng > m-(dp[4].neng-dp[3].neng)) cout<<2<<endl;
                else cout<<3<<endl;
            }

        }
        else{
              if(dp[5].neng - dp[4].neng > m){
                if(dp[4].neng - dp[3].neng > m){
                    if(dp[3].neng - dp[2].neng > m){
                        if(dp[2].neng-dp[1].neng>m) cout<<1<<endl;
                        else cout<<2<<endl;
                    }
                    else{
                        if(dp[3].neng-dp[1].neng>m-(dp[3].neng-dp[2].neng)) cout<<2<<endl;
                        else cout<<3<<endl;
                    }
                }
                else{
                    if(dp[4].neng-dp[2].neng > m-(dp[4].neng-dp[3].neng)) cout<<2<<endl;
                    else cout<<3<<endl;
                }
            }
            else{
                if(dp[5].neng-dp[3].neng > m-(dp[5].neng-dp[4].neng)) cout<<2<<endl;
                else{
                    cout<<3<<endl;
                }
            }

        }
    }
    return 0;

}
// yao de ling fen le , hao nan guo     T-T T-T T-T T-T T-T T-T































































