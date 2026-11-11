#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	long long n,m;
	cin >> n >> m;
	long long a;
	vector<long long> s;
	for(long long i=0; i<n; i++){
		cin >> a;
		s.push_back(a);
	}
	sort(s.begin(), s.end());
	
	vector<long long> cf;//
	cf.push_back(0);
	for(long long i=1; i<n; i++){
		cf.push_back(s[i]-s[0]);
	}
	
	vector<long long> cfq;//
	for(long long i=1; i<n; i++){
		cfq.push_back(cf[i]-s[0]);
	}
	vector<long long> cf1;//
	cf1.push_back(0);
	for(long long i=1; i<n; i++){
		cf1.push_back(s[i]-s[i-1]);
	}
	
	/*for(int i=0; i<n; i++){
		cout << cf[i] << ' ';
	}cout << '\n';*/
	
	long long ans=1;
	long long i=0, j=0; // i=kuai, j=man
	long long cnt=0;
	while(i<n){
		if (cnt<=m && j <n){
			
			cnt += cf1[j+1]*(abs(j-i+1));
			long long p = cf1[j+1]*(abs(j-i+1));
			j++;
			//cout << cf1[j] << '*' << abs(j-i) << '=' <<p << '\n';
			ans = max(ans, j-i);
		}else{
			long long p1 = cf[j-1]-cf[i];
			cnt -= cf[j]-cf[i];
			//cnt = max(0,cnt);
			i++;
		}
	}
	//cout << s[0] << ' ' << s[n-1] << '\n'; 
	//cout << cf[0] << ' ' << cf[n-1] << '\n'; 
	cout << ans;
	
	return 0;
	fclose(stdin);
	fclose(stdout);
} 
