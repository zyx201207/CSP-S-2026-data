#include <bits/stdc++.h>
using namespace std;
int a[500005];
int k[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	int round=1;
	while(round<=n){
		vector<int> s(n);
		for(int i=round-1;i<n;i++){
			for(int j=-n;j<i+n;j++){
				if(s[j+n]==a[i]){
					for(int x=1;x<=i-j+1;x++){
						s.erase(s.begin()+x);
					}
				}
			}
			s.push_back(a[i]);
		}
		for(int i=0;i<s.size();i++){
			k[s[i]-1]++;
		}
		for(int i=0;i<s.size();i++){
			s.erase(s.begin()+0);
		}
		round++;
	}
	for(int i=0;i<m;i++){
		cout << k[i] << " ";
	}
	return 0;
}
