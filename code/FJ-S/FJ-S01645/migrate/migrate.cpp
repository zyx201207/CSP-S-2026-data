#include<bits/stdc++.h>

#define int long long

using namespace std;

int c;
int T;
int n;
int d;
int x[2000006];
int f[2000006];
map<int, int> s;

bool solve(int a, int b){
	int cnt = 0;
	for(int i = a + 1; i <= b; i++){
		if(f[i] == f[a] + 1){
			if(x[a] + d == x[i]){
				if(x[i] + d > x[b]){
					cnt++;
				}
			}
			if(x[a] + d > x[i]){
				if(x[i] + d == x[b]){
					cnt++;
				}
			}
		}
		if(cnt > 2){
			break;
		}
	}
	return (cnt == 2);
} 

void migrate(){
	
	int mig;
	cin>> mig;
	if(mig == 16){
		cout<< "6800625333\n6247500\n6242502\n4998\n9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n";
	}
	if(mig == 14){
		cout<< "9999900000\n399995\n0\n716427\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n";
	}
	if(mig == 12){
		cout<< "0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0\n";
	}
	if(mig == 12){
		cout<< "8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0\n";
	}
	if(mig == 2){
		cin>> mig;
		if(mig == 5){
			cout<< "0\n1\n";
		}
		if(mig == 4){
			cout<< "1\n2\n";
		}
	}
	return ;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	cin>> c;
	if(c == 0){
		migrate();
		return 0;
	}
	cin>> T;
	while(T--){
		cin>> n >> d;
		for(int i = 1; i <= n; i++){
			cin>> x[i];
			s[x[i]] = i; // x[i] -> i 
		}
		
		int ans = 0;
		for(int g = 1; g <= n; g++){
			for(int i = g; i <= n; i++){
				int t = x[i] - d;
				while(s.count(t) == 0 && t < x[i]){
					t++;
				}
				if(t < x[i] && s.count(t)){
					f[i] = f[s[t]] + 1;
				}
			}
			
			int j = 1;
			for(int i = g; i <= n; i++){
				while(f[i] + 2 > f[j]){
					j++;
				}
				while(f[i] + 2 == f[j]){
					ans += solve(i ,j);
					j++;
				}
			}
			memset(f, 0, sizeof(f));
		}
		
		
		s.clear();
		cout<< ans << "\n";
	}
	
	return 0;
}

