#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
long long a[N],pre[N];
int n;
long long m;
struct stu{
	long long pree;
	int pos;
}b[N];
bool res(stu a,stu b){
	if(a.pree<=b.pree)return true;
	return false;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i = 1;i <= n;i++){
		pre[i] = a[i]-a[i-1]; 
		b[i].pree = pre[i];
		b[i].pos = i;
	} 
	sort(b+1,b+n+1,res);
	int maxn = -0x3f;
	for(int i = 1;i <= n;i++){
		long long sum = 0;
		int ans = 0;
		for(int j = b[i].pos-1;j >= 1&&sum<=m;j--){
			sum+=a[b[i].pos]-a[j];
			ans++;
			if(sum==m){
				cout << ++ans << "\n";
				return 0;
			}
			
			
		}
		if(ans==n){
			cout << ans << "\n";
			return 0;
		}
		maxn = max(maxn,ans);
	}
	cout << maxn << "\n";
	return 0;
}

