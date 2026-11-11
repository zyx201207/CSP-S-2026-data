#include<bits/stdc++.h>
using namespace std;

char a[500005];
long long b[300005];

int main(){
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	long long n, m;
	string s;
	cin>>n>>m;
	for(long long i = 1; i <= n; i++){
		cin>>a[i];
	} 
	for(long long i = 1; i <= n; i++){
		s = "";
		for(long long j = i; j <= n; j++){
			long long k = s.find(a[j]);
			if(k == -1){
				s = s+a[j];
			}
			else{
				s.erase(k);
				s = s+a[j];
			}
		}
		for(long long i = 0; i < s.size(); i++){
			b[s[i]-'0']++;
		}
	}
	for(long long i = 1; i <= m; i++){
		cout<<b[i]<<' ';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
