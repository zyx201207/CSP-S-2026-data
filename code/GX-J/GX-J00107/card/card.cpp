#include<bits/stdc++.h>
using namespace std;
int a[6],ans[4];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	int t,h;
	for(int i=1;i<=n;i++){
		t=a[i];
		for(int j=i;j<=n;j++){
			if(a[j]!=t) h=a[j];
			if(a[j]==t) h=0;
		}
		if(t==1) ans[3]++;
		else ans[2]++;
		if(h==1) ans[3]++;
		if(h==2) ans[2]++;
	} if(a[1]==1) ans[3]=n;
	else ans[2]=n;
	int aa=ans[2];
	cout<<ans[3]<<' '<<aa;
	return 0;
}
