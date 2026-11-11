#include<bits/stdc++.h>
using namespace std;
const int N= 2e5+5;
int n,a[N],m,del[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >>m;
	for(int i = 1;i<=n;i++){
		cin >>a[i];
	}
	int ans = 0;
	for(int j = 30;j>=0;j--){
		int cnt = 0;
		for(int i = 1;i<=n;i++){
			if(del[i]) continue;
			if(a[i]&(1<<j)) cnt++;
		}
//		cout <<cnt << " ";
		if(cnt>=m){
			for(int i = 1;i<=n;i++){
				if(!(a[i]&(1<<j))) del[i]=1;
			}
			ans+=(1<<j);
		}
	}
	cout <<ans;
}
