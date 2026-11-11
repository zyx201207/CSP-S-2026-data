#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	vector<int> a(n+1,0);
	bool ok=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]) ok=0;
	}
	if(ok){
		vector<int> u(m+1,0);
		vector<int> kk(m+1,0);
		for(int i=1;i<=n;i++){
			kk[a[i]]++;
		}
		if(kk[a[1]]%2==1) u[a[1]]=1;
		for(int i=1;i<=n-1;i++){
			kk[a[i]]--;
			for(int j=1;j<=m;j++){
				if(kk[j]%2==1) u[j]++;
			}
		}
		for(int i=1;i<=m;i++){
			cout<<u[i]<<" ";
		}
		return 0;
	}
	vector<int> h(n+1,0);
	for(int i=1;i<=n;i++){
		vector<int> q(n+1,0);
		for(int j=i;j<=n;j++){
			if(q[a[j]]==0){
				q[a[j]]=1;
			}else{
				for(int t=j;t>=i;t--){
					if(a[j]==a[t]) break;
					else q[a[t]]=0;
				}
				q[a[j]]=0;
			}
		}
		for(int i=1;i<=m;i++){
			if(q[i]) h[i]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<h[i]<<" "; 
}
