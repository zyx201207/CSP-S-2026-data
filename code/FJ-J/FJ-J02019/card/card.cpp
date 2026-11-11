#include<bits/stdc++.h>
using namespace std;
int t[300005];
int a[500005];
int s[300005];
int ans[300005];
int vi[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[a[i]]=i;
		t[a[i]]++;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			vi[j]=0;
		}
		for(int j=s[i];j<=n;j++){
			if(!vi[a[j]]){
				ans[a[j]]+=t[i];
				vi[a[j]]=1;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}

