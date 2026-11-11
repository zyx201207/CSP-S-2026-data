
#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],sum[3005],ans[3005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    memset(ans,0,3003);
    memset(sum,0,3003);
    cin>>n>>m;
    if(n>505){
		for(int i=1;i<=m;i++) cout<<"0 ";
		return 0;
	}
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int dele=1;
    for(int th=1;th<=n;th++){
		for(int p=1;p<=m;p++){
			ans[p]+=sum[p];
			sum[p]=0;
		}
		for(int p=th;p<=n;p++) sum[a[p]]++;
        for(int i=th;i<=n;i+=dele){
            for(int j=i+1;j<=n;j++){
                sum[a[j]]--;
                if(a[i]==a[j]){
                    dele=j-i;
                    break;
                }
                if(j==n){
                    for(int p=i+1;p<=n;p++)
                        sum[a[p]]++;
                    dele=1;
				}
			}
		}
	}
    for(int i=1;i<=m;i++){
        cout<<ans[i]+sum[i]<<" ";
    }
    return 0;
}
