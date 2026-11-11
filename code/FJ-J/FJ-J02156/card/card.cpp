#include<bits/stdc++.h>
using namespace std;
const int N = 5e5; 
long long n,m;
long long a[N];
int main(){
	freopen("card.in" , "r" , stdin);
	freopen("card.out" , "w" , stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	long long ans1 = 0;
	long long ans2 = 0;
	for(int i = 1; i <= n; i++){
		string s;
		for(int j = i; j <= n; j++){
			int k = a[j];
			int cnt = 0;
			for(int q = 0; q < s.size(); q++){
				if(s[q] != k){
					cnt++;
				}
			} 
			if(cnt == s.size()){
				char p = (k + '0');
				s = s + p; 
				cout << s;
			}else{
				for(int q = 0; q < s.size(); q++){
					if(s[q] == k){
					   string s1;
					   for(int w = 0; w < q; w++){
					   	   s1 += s[w];
					   }
					   s = s1;
					   char p = (k + '0'); 
					   s = s + p;
					   cout << s;
					}
				}
			}
		}
		int ans11 , ans22;
		for(int j = 0; j < s.size(); j++){
			if(s[j] == '1'){
				ans11 = 1;
			}else if(s[j] == '2'){
				ans22 = 1;
			}
		}
		if(ans11 == 1){
			ans1++;
		}
		if(ans22 == 1){
			ans2++;
		}
	}
	cout << ans1 << " " << ans2 << endl;
	return 0;
} 
