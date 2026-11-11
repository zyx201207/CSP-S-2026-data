#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],st[500005],tp=0,ans[300005];
int qw(int h){
	for(int i=1;i<=tp;i++){
		if(st[i]==h){
			return i;
		}
	}
	return -1;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
;	ios::sync_with_stdio(0);;
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		tp=0;
		for(int j=i;j<=n;j++){
			int u=qw(a[j]);
			if(u==-1){
				st[++tp]=a[j];
			}else{
				tp=u;
			}
		}
		for(int j=1;j<=tp;j++){
			ans[st[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}

