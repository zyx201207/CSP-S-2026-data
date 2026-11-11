#include <bits/stdc++.h>

using namespace std;

int n,m;
int a[200005];
vector<int> pw(35);

bool cmp(const int &x,const int &y){
	return x > y;
}

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(0) -> ios::sync_with_stdio(0); 
	
	pw[0] = 1;
	int i;
	for(i = 1;i <= 30;i++){
		pw[i] = pw[i - 1] * 2;
	}
	
	cin >> n >> m;
	for(i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a + 1,a + n + 1,cmp);
	int cnt = 0;
	i = 0;
	int ans = 0;
	while(cnt < m){
		i++;
		if(*lower_bound(pw.begin(),pw.end(),a[i]) == a[i]){
			continue;
		}
		if(cnt == 0)
			ans = a[i];
		else
			ans = ans & a[i];
		//cout << a[i] <<' ';
		cnt++;
	}
	cout << ans;
	return 0;
} 
