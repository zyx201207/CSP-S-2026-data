#include<bits/stdc++.h>
using namespace std;
int x = 1, y = 1, ssz = 1, bsz = 0, ans = 1;
long long mp[500005], ssum = 0ll, bsum = 0ll;
priority_queue <pair <long long, int>> sml;
priority_queue <pair <long long, int>, vector <pair <long long, int>>, greater <pair <long long, int>>> bg;
void check(){
	while(!sml.empty() && sml.top().second < x){
		sml.pop();
	}
	while(!bg.empty() && bg.top().second < x){
		bg.pop();
	}
	return ;
}
void blc(){
	while(ssz >= bsz + 2){
		if((!sml.empty() && sml.top().second < x) || (!bg.empty() && bg.top().second < x)){
			check();
		} else {
			bsum += sml.top().first;
			ssum -= sml.top().first;
			bg.push(sml.top());
			sml.pop();
			bsz++;
			ssz--;
		}
	}
	while(ssz < bsz){
		if((!sml.empty() && sml.top().second < x) || (!bg.empty() && bg.top().second < x)){
			check();
		} else {
			bsum -= bg.top().first;
			ssum += bg.top().first;
			sml.push(bg.top());
			bg.pop();
			ssz++;
			bsz--;
		}
	}
	check();
	return ;
}
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long long n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> mp[i];
	}
//	sort(mp + 1, mp + n + 1);
//	cout << mp[n / 2] << " " << mp[n / 2 + 1];
//	long long sum = 0ll;
//	for(int i = 1; i <= n / 2; i++){
//		sum += mp[i];
//	}
//	cout << sum << " ";
//	sum = 0;
//	for(int i = n / 2 + 1; i <= n; i++){
//		sum += mp[i];
//	}
//	cout << sum;
	bool l = 1;
	sml.push({mp[1], 1});
	ssum = mp[1];
	while(x <= y && y <= n){
		if(x == y && y == n){
			break;
		}
		if(l && y < n){
			y++;
			blc();
			if(sml.empty() || mp[y] <= sml.top().first){
				ssum += mp[y];
				ssz++;
				sml.push({mp[y], y});
			} else {
				bsum += mp[y];
				bsz++;
				bg.push({mp[y], y});
			}
		} else {
			blc();
			if(mp[x] <= sml.top().first){
				ssz--;
				ssum -= mp[x];
			} else {
				bsz--;
				bsum -= mp[x];
			}
			x++;
		}
		blc();
		check();
		long long k = sml.top().first;
//		cout << x << " " << y << " " << ssz << " " << bsz << " "  << sml.top().first << " " << bg.top().first << " "<< ssum << " " << bsum << " : " << m - (bsum - (k * bsz) + (k * ssz) - ssum) << "\n";
		if(bsum - ssum + ((y - x + 1) % 2) * k > m){
			l = 0;
		} else {
			ans = max(ans, y - x + 1);
			l = 1;
		}
	}
	cout << ans;
	return 0;
} 
