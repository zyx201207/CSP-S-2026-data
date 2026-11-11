#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,ans[300001],del[300001],card[500001],deletegoal;
bool deleting=false;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cout.tie(0);
    cin.tie(0);
    cin >> n>>m;
    for(ll i=1;i<=n;i++){
        ll x;
        cin >> x;
        card[i]=x;
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){

            del[card[j]]++;
        }
        for(int w=1;w<=n;w++){

        }

        for(int k=i;k<=n;k++){

            //    cout << deleting<< '-'<<deletegoal<< ' '<<card[k]<<endl;
            if(deleting==true&&deletegoal==card[k]){
                deleting=false;
            }
            if(deleting==true&&deletegoal!=card[k]){
                if(del[card[k]]>1){
                    del[card[k]]--;
                }
                continue;
            }
            ll pls=card[k];
            if(del[pls]>1){
                del[pls]--;
                deleting=true;
                deletegoal=pls;
            }else{
                ans[pls]++;
            //    cout<< pls<<endl;
            }
        }

     memset(del,0,300001);
     deleting=false;
     deletegoal=0;
    // cout <<endl;
    }
    for(int i=1;i<=m;i++){
        cout << ans[i]<< ' ';
    }
    return 0;
}
