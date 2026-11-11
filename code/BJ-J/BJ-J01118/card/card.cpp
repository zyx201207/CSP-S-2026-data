#include <bits/stdc++.h>
using namespace std;

int n,m;
int a[500050],sum[300050],ans[300050];

int main(){
    freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    cin >> n >> m;
    for (int i=1;i<=n;i++){
        cin >> a[i];
    }
    memset(ans,0,sizeof(ans));
    for (int i=1;i<=n;i++){
        memset(sum,0,sizeof(sum));
        for (int j=i;j<=n;j++){
            if (sum[a[j]]==0){
                sum[a[j]]++;
            }
            else{
                sum[a[j]]=1;
                for (int k=j-1;k>=1;k--){
                    if (a[k]==a[j]) break;
                    if (sum[a[k]]>0){
                        sum[a[k]]--;
                    }
                }
            }
        }
        for (int j=1;j<=m;j++){
            ans[j]+=sum[j];
        }
    }
    for (int i=1;i<=m;i++){
        cout << ans[i] << ' ';
    }
	return 0;
}
