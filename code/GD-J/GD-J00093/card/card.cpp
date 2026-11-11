#include <iostream>
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m,a[N],ans[M],lst[M];
bool vis[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	bool A=1;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		if(i>1) A&=(a[i-1]<=a[i]);
		lst[a[i]]=i;
	}
	if(A){
		for(int i=1;i<=n;i++){
			ans[a[i]]+=1;
			ans[a[n]+1]-=1;
		}
		for(int i=1;i<=m;i++){
			ans[i]+=ans[i-1];
			cout << ans[i] << ' ';
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			ans[a[j]]++;
			j=lst[a[j]];
		}
	}
	for(int i=1;i<=m;i++){
		cout << ans[i] << ' ';
	}
	return 0;
}
