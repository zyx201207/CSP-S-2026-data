#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e3+10;
int n,m,a[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n>> m;
	bool flag=0;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(a[i]<a[i-1]) flag=1;
	}
	vector<int> ans(m+1,0);
	if(n<=500){
		for(int i=1;i<=n;i++){
			vector<int> b(m+1,0);
			for(int j=i;j<=n;j++){
				if(!b[a[j]]) b[a[j]]=j;
				else{for(int k=b[a[j]]+1;k<j;k++) b[a[k]]=0;b[a[j]]=j;}
			}
			for(int j=1;j<=m;j++) ans[j]+=(b[j]?1:0);
		}
		for(int i=1;i<=m;i++) cout << ans[i] << " ";
	}
	else if(m==2){
		vector<int> b;
		for(int i=1;i<=n;i++){
			if(a[i]!=a[i-1]) b.push_back(a[i]);
		}
		int k=b.size();
		ans[a[n]-1]=n;ans[!(a[n]-1)]=k/2;
		cout << ans[0] << " " << ans[1];
	}else {
		for(int i=n;i>=1;i--) ans[a[i]]=max(ans[a[i]],i);
		for(int i=1;i<=m;i++) cout << ans[i] << " ";
	}
	return 0;
}
