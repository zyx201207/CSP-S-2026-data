#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 7;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
map<int,int> mp;
int n,m; 
int a[N];
map<int,int> d;
signed main(){
//	记得取消注释！！！ 
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	int maxi = 0;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	sort(a + 1,a + n + 1);
	int cnt = 0;
	for(int i = 1; i <= n; i++){
		mp[a[i]]++;
		cnt = max(cnt,mp[a[i]]);
	//	maxi = max(maxi,mp[a[i]]);
		if(i == 1) continue;
		d[i - 1] = i;
	}
	for(int i = 1; i < n; i = min(n,i + mp[a[i]])){
		int w = a[ i + mp[a[i]]] - a[i];
		q.push({w * mp[a[i]],i});
		d[i] = i + mp[a[i]];
	}
//	d[n] = n + 1;
	
	while(!q.empty()){
		auto x = q.top();
		q.pop();
		int l = x.second,r = d[x.second],w = x.first;
	//	cout << l << " " << r << " " << w << " m:" << m << " maxi: " << maxi << endl;
	//	cout << mp[a[l]] << ' ' << mp[a[r]] << endl;
		if(m >= w and mp[a[r]] + mp[a[l]] > maxi){
			
			mp[a[r]] += mp[a[l]];
			m -= w;
			maxi = mp[a[r]];//cout << l << " " << r << " " << maxi << endl << endl;
			int v = a[d[r]] - a[r];
		//	cout << v << ' ' << mp[a[r]] << endl;
		//	cout << "---------------\n";
			q.push({v * mp[a[r]],r});
		}
	}
	cout << max(cnt,maxi) << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
} //5 8 -3 -1 2 2 7
