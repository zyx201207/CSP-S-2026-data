#include<bits/stdc++.h>
using namespace std;
int n,a[50005],ans[50005],m,b[50005],cnt;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		cnt=0;
		for(int j=i;j<=n;j++){
			int dz=lower_bound(b+1,b+cnt+1,a[j])-b;
			if(b[dz]==a[j]) cnt=dz-1;
			b[++cnt]=a[j];
		}
		for(int j=1;j<=cnt;j++)ans[b[j]]++;
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	cout<<"\n";
	return 0;
}
