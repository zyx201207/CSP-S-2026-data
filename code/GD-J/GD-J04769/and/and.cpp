#include <bits/stdc++.h>
using namespace std;
const int N=200005;
long long a[N],b[N];
bool used[N];
long long Max=-1e9;
long long n,m;
void dfs(int pos){//pos:Ìîµ½ÄÄ¸öÊý
	long long sum=0;
	if (pos==m+1){
		sum=b[1];
		for (int i=2;i<=m;i++){
			sum&=b[i];
		}
		Max=max(Max,sum);
		return ;
	}
	for (int i=1;i<=n;i++){
		if (used[i]==0){
			used[i]=1;
			b[pos]=a[i];
			dfs(pos+1);
			used[i]=0;
			b[pos]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i=1;i<=n;i++){
		cin >> a[i];
	}
	dfs(1);
	cout << Max;
	return 0;
} 
