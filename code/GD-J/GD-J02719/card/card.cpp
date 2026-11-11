#include <bits/stdc++.h>
using namespace std;
int cnt[500005];
bool liv[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,a[600005],play[400005];
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    int now=1;
    for (int i=1;i<=n;i++){
        for (int j=i;j<=n;j++){
            play[now]=a[j];
            if(!liv[a[j]]){
            	liv[a[j]]=true;
            }else{
                liv[play[now]]=false;
                play[now]=0;
                now--;
            	while (play[now]!=a[j]){
            		liv[play[now]]=false;
            		play[now]=0;
            		now--;
				}
				liv[a[j]]=true;
			}
            now++;
        }
        for (int j=1;j<now;j++){
            cnt[play[j]]++;
            play[j]=0;
        }
        now=1;
        for (int j=1;j<=m;j++){
            liv[j]=false;
        }
    }
    for (int j=1;j<=m;j++){
        cout<<cnt[j]<<" ";
    }
    return 0;
}

