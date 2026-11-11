#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m; cin >> n >> m;
	vector<long long> k;
	for(int i = 0;i < n;i++){
		long long a; cin >> a;
		k.push_back(a);
	}
	sort(k.begin(),k.end());
	if(m == 1){
		cout << k[k.size()-1];
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	if(m == n){
		long long sum = k[0];
		for(int i = 0;i < k.size();i++){
			sum = sum&k[i];
		}
		cout << sum;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	if((m+1) == n){
		long long max = 0;
		long long sum = k[0];
		for(int j = 0;j < k.size();j++){
			for(int i = 0;i < k.size();i++){
				if(i == j) continue;
				sum = sum&k[i];
			}
			if(sum > max) max = sum;
		}
		cout << max;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	if(m == 2){
		long long max = 0;
		long long sum;
		for(int j = 0;j < k.size();j++){
			sum = k[j];
			for(int i = j+1;i < k.size();i++){
				if(i == j) continue;
				if((sum&k[i]) > max) max = sum&k[i];
			}
		}
		cout << max;
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	else{
		long long sum = 0;
		int now = m;
		for(int i = k.size()-1;i >= 0;i--){
			if(now <= 0) break;
			if(i == (k.size()-1)){
				sum = k[i];
				now--;
				continue;
			}
			sum = sum&k[i];
			now--;
		}
		cout << sum;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
