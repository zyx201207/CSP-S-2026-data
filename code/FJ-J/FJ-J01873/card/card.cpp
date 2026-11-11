#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m,a[N],ans[N];
vector<long long> b(N);
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	int f=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1])f=1;
	}
	if(f==0){
		for(int i=n;i>=1;i--){
			if(b[a[i]]==0){
				b[a[i]]=1;
				ans[a[i]]=i;
			}
		}
		for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
		return 0;
	}
	for(int i=1;i<=n;i++){//起点 
		long long tot=i-1;
		b.clear();
		for(int j=i;j<=n;j++){//每一步 
			for(int k=i;k<=tot;k++){
				if(b[k]==a[j]){
					tot=k-1;
					break;
				}
			}
			b[++tot]=a[j];
		}
		for(int j=i;j<=tot;j++)ans[b[j]]++;
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
