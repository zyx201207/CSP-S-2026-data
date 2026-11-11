#include<bits/stdc++.h>
using namespace std;
long long ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	long long n,m;
	cin>>n>>m;
	vector<long long> a(n+1),b(n+1);
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		b[i]=0;
		for(int j=i+1;j<=n;j++){
			if(a[i]==a[j]){
				b[i]=j;
				continue;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(b[j]==0)
				ans[a[j]]++;
			else{
				j=b[j]-1;
			}
		}
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<" ";
	return 0;
}
