#include <bits/stdc++.h>
using namespace std;

const int MAXN = 500005;
pair <long long ,long long> a[MAXN]; 
int b[MAXN];

int cmp(pair<long long,long long> x,pair<long long,long long>y){
	return x.first < y.first;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	int n,m;
	cin >> n >> m;
	int tmp = 0,cnt = 0,z = -1;
	for(int i=1;i<=n;i++){
		cin >> b[i];
	}
	sort(b+1,b+1+n);
	for(int i=1;i<=n;i++){
		int x = b[i];
		if(tmp == x){
			cnt++;
		}
		else{
			z++;
			a[z] = {tmp,cnt};
			tmp = x;
			cnt = 1;
		}
	}
	a[++z] = {tmp,cnt};
	long long ans = a[0].second;
	for(int i=1;i<=z;i++){
		long long k = m,temp = a[i].second;
		for(int j = i-1;j>=1;j--){
			int l = 0;
			while(l!=a[j].second&&(k+a[j].first-a[i].first)>=0){
				temp ++;
				l++;
				k-= (a[i].first-a[j].first);
			}
		}
		ans = max(ans,temp);
	}
	cout << ans;
	return 0;
}
