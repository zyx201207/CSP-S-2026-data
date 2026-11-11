#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a[N];
bool ok[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	int ans=0;
	for (int i=30;i>=0;i--){
		int cnt=0;
		vector<int> box;
		for (int j=1;j<=n;j++){
			if (ok[j]) continue;
			if ((a[j]>>i)&1) cnt++;
			else box.push_back(j);
		}
		if (cnt>=m){
			ans+=(1<<i);
			for (auto x:box) ok[x]=1;
		}
	}
	printf("%d",ans);
	return 0;
} 
