#include<bits/stdc++.h>
using namespace std;
const int N=5e5+8,M=3e5+5;
int ans[N],a[N],n,m,jian[N],tong[N],tong1[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans[i]=i;
		tong[a[i]]++;
	}
	for(int i=1;i<=n;i++){
		if(tong[a[i]]>1){
			int ji=jian[i];
			for(int j=i;j<=n;j++){
				ans[j]-=i;
				ans[j]+=ji;
				jian[j]++;
				if(a[j]==a[i]&&j!=i) break;
			}
		}
		tong[a[i]]--;
	}
	for(int i=1;i<=n;i++){
		tong1[a[i]]+=ans[i];
	}
	for(int i=1;i<=m;i++){
		printf("%d ",tong1[i]);
	}
	return 0;
}
