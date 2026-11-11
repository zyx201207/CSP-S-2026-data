#include<bits/stdc++.h>
using namespace std;
int a[200005];
int vis[200005];
int next1[200005];
int flag[200005];
int flag2[200005];
int flag3[200005];
int pre[200005];
queue<int>q;
int wei[200005];
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		q.push(i);
	}
	for(int i=n; i>=1; i--) {
		if(flag2[a[i]]==0) {
			flag[a[i]]=i;
			flag2[a[i]]=i;
		} else {
			vis[i]=flag2[a[i]];
			next1[i]=flag[a[i]];
			pre[flag[a[i]]]=i;
			flag[a[i]]=i;
		}
	}
	for(int i=1; i<=n; i++) {
		if(flag3[a[i]]==0) {
			flag3[a[i]]=i;
		}
	}
	for(int i=1; i<=n; i++) {
		//cout<<next1[i]<<" "<<pre[i]<<" "<<flag2[i]<<endl;
	}
	for(int i=1; i<=m; i++) {
		int ans=0;
		int op=flag2[i],pp=flag2[i];
		while(1) {

			while(flag2[a[op-1]]<=pp) {
				op--;
				if(op==0){
					op=1;
					break;
				}
			}
			ans=ans+pp-op+1;
			while(pp>=op) {
				pp=pre[pp];
				if(pp==0) {
					break;
				}
			}
			if(pp==0 || op==1) {
				break;
			}
			op=pp;
			
		}
		//cout<<ans<<" "<<pp<<" "<<op<<endl;
		cout<<ans<<" ";
	}
	return 0;
}