#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[500005],b[500005],c[500005];
bool f[500005];
long long ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[c[a[i]]]=i;
		c[a[i]]=i;
	}
	for(int i=n;i>=1;i--){
		for(int j=i;j<=n;j++){
			while(b[j]) j=b[j];
			f[a[j]]=1;
		} 
		for(int i=1;i<=m;i++)
			if(f[i]) ans[i]++,f[i]=0;
	}
	ans[a[n]]=n;
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
}
