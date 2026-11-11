#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[3005],pre[3005],cnt,o;
bool b;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		cout<<n;
		return 0;
	}else if(m<=2){
		ans[a[n]]=n;
		for(int i=1;i<=n-1;i++){
			if(a[i]==a[n]) cnt++;
			else o=i;
		}
		ans[a[o]]=n-1-cnt;
		for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
		return 0;
	}
	else if(m>3000){
		for(int i=m;i>=1;i--){
			cout<<n-i+1<<' ';
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) pre[j]=0;
		for(int j=i;j<=n;j++){
			if(pre[a[j]]!=0){
				for(int k=pre[a[j]];k<j;k++){
					ans[a[k]]--;
				}
			}
			ans[a[j]]++;
			pre[a[j]]=j;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
