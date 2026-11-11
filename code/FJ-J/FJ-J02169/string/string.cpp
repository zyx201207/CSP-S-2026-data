#include<bits/stdc++.h>
using namespace std;
const long long MAXN=1e8+10;
char a[MAXN];
long long n,sum,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		char y;
		cin>>x>>y;
		for(int j=1;j<=x;j++){
			a[++sum]=y;
		}
	}
	for(int i=1;i<=sum/2;i++){
		if(a[i]!=a[sum-i+1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
