#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],num[300005],b[300005];
bool d[6005][6005],f[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	bool fl=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]&&i!=1)fl=1;
		num[a[i]]++;
	}
	if(!fl){
		int ans=0;
		for(int i=1;i<=m;i++){
			ans+=num[i];
			cout<<ans<<' ';
		}
		return 0;
	}
	for(int i=n;i>=1;i--){
		if(!f[a[i]]){
			f[a[i]]=1;
			for(int j=1;j<=m;j++){
				if(j==a[i])d[a[i]][j]=1;
				else d[a[i]][j]=d[a[i+1]][j];
			}
		}
	}
	for(int i=1;i<=m;i++){
		int ans=0;
		for(int j=1;j<=m;j++)ans+=d[j][i]*num[j];
		cout<<ans<<' ';
	} 
	return 0;
}

