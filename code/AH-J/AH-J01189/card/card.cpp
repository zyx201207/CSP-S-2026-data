#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[1000010],cnt[1000010];
bool flag[1000010];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
        cin>>a[i];
	}
	for(int i=1;i<=n;i++){
        memset(flag,true,sizeof(flag));
        for(int j=i;j<=n;j++){
            for(int k=j-1;k>=i;k--){
                if(a[k]==a[j]&&flag[k]==true){
                    for(int i_=k;i_<j;i_++){
                        flag[i_]=false;
                    }
                }
            }
        }
        for(int j_=i;j_<=n;j_++){
            if(flag[j_]==true){
                cnt[a[j_]]++;
            }
        }
	}
	for(int i=1;i<=m;i++){
        cout<<cnt[i]<<" ";
	}
    return 0;
}
