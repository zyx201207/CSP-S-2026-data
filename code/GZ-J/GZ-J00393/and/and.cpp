#include<bits/stdc++.h>
using namespace std;

int n,m,a[1000005],ans = 0;
void f(int x){
	int b = 0;
	while(x){
		if(x&1)a[b]++;
		x = (x>>1);
		b += 1;
	}
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	vector<int>b(n + 1);
	for(int i = 1;i <= n;i++){
		cin>>b[i];
		f(b[i]);
	}
	int cnt = 0;
	for(int i = 100;i >= 0;i--){
		if(a[i] >= m){
			ans += (1<<i);
			cnt++;
		}
		if(cnt == m)break;
	}
	cout<<ans;
	return 0;
}
