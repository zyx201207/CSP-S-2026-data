#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[300005],last[500005],num[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			num[a[j]]++;
			if(num[a[j]]==2){
				for(int k=last[a[j]];k<j;k++) num[a[k]]--;
			}
			last[a[j]]=j;
		}
		for(int j=1;j<=m;j++){
			if(num[a[j]]>0) ans[a[j]]++;
		}
		for(int j=1;j<=m;j++){
			num[a[i]]=0;
		}
	}
	for(int i=1;i<=n;i++){
		cout<<ans[a[i]]<<" ";
	}
	return 0;
}
