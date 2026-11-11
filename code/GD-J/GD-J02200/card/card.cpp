#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[300005],lst[500005],stk[500005],cnt=0;
int main(){
	std::ios_base::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >>n>>m;
	for(int i=1;i<=n;i++) cin >>a[i],lst[i]=i;
	for(int i=1;i<n;i++){
		if(lst[i]==i){
			for(int j=i+1;j<=n;j++){
				if(a[i]==a[j]) lst[j]=i;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(lst[j]!=j){
				while(cnt!=lst[j]) stk[cnt]=0,cnt--;
				stk[cnt]=0,cnt--;
			}
			stk[++cnt]=a[j];
		}
		for(int j=1;j<=cnt;j++) ans[a[j]]++,a[j]=0;
		cnt=0;
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
