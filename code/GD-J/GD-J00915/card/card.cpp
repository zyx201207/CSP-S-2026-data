#include<bits/stdc++.h>
using namespace std;
long long a[1000100];
long long g[1000100];
long long sum[1000100];
int top = 0;
void solve(){
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		top = 0;
		for(int j=i;j<=n;j++){
			bool f = false;
			int target = 0;
			for(int k=1;k<=top;k++){
				if(g[k]==a[j]){
					f = true;
					target = k;
					break;
				}
			}
			if(f) top = target;
			else g[++top] = a[j];
		}
		for(int j=1;j<=top;j++){
			sum[g[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<sum[i]<<' ';
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	solve();
	return 0;
}
