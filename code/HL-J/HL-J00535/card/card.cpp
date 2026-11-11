#include <bits/stdc++.h>
using namespace std;
int n = 0;
int m;
int num[500005] = {};
int main(){
	cin >> n >> m;
	for(int i = 0;i < n;i++){
		cin >> num[i];
	}
	for(int o = 1;o <= m;o++){
		for(int i = 0;i < n;i++){
			vector<int> s;
			s.push(num[i]);
			for(int j = i+1;j < n;j++){
				if(p[i] == num[j]){
					
				}
			}
		}
	}
	return 0;
}
