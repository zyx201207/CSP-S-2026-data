#include<bits/stdc++.h>
using namespace std;
#define long long int
int a[100005],m,n,maxn;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(m == 1){
		cout<<0;
		return 0;
	}
	for(int i = 1;i<=n;i++){
		cin>>a[i];		
	}
	for(int i = 1;i<=n;i++){
		int num,cnt = a[i];
		for(int j = 1;j<=n;j++){
			num = (cnt&a[j]);
		}
		maxn = max(num,maxn);
	}
	cout<<maxn;
	return 0;
}
