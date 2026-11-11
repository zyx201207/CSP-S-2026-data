#include<bits/stdc++.h>
using namespace std;

int n,m,a[500009],b[500009];
stack<int>s;

int main () {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++){
		int mmm[300009] = {0};
		for(int j = i;j <= n;j++){
			if(mmm[a[j]] == 0){
				s.push(a[j]);
				mmm[s.top()] = 1;
			}else{
				while(1){
					if(s.top()!=a[j]){
					mmm[s.top()] = 0;
					s.pop();
					}else{
						break;
					}
				}
			}
			for(int i = 0;i<s.size();i++){
				b[s.top()]++;
				s.pop();
			}
		}
	}
	for(int i = 1;i <= n;i++){
		cout << b[i];
	}
	return 0;
}

