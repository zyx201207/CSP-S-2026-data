#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],cnt[300005],q[500005];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	bool x=1;
	for(int i=2;i<=n;i++) if(a[i]<a[i-1]) x=0;
	if(x==1){
		for(int i=1;i<=n;i++){
			if(i==1) cnt[a[i]]=1;
			else{
				if(a[i]==a[i-1]) cnt[a[i]]++;
				else{
					cnt[a[i]]=i;
				}
			}
		}
		for(int i=1;i<=m;i++) cout<<cnt[i]<<" ";
		return 0;
	}
	for(int i=1;i<=n;i++){
		fill(q,q+n+1,0);
		int ta=0,last[300005];
		fill(last,last+m+1,-1);
		for(int j=i;j<=n;j++){
			if(last[a[j]]!=-1){
				ta=last[a[j]];
				fill(last,last+m+1,-1);
				for(int k=1;k<=ta;k++) last[q[k]]=k;
			}
			else q[++ta]=a[j],last[a[j]]=ta;
		}
		int chu[300005];
		fill(chu,chu+m+1,0);
		for(int j=1;j<=ta;j++){
			if(chu[q[j]]==0) cnt[q[j]]++,chu[q[j]]=1;
		}
	}
	for(int i=1;i<=m;i++) cout<<cnt[i]<<" ";
	return 0;
}
