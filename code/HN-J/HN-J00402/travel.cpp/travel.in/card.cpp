#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	vector<int> v;
	int n, m;
	cin >> n >> m;
	for(int i=0; i<n; i++){
		int k;
		cin >> k;
		for(int j=0; j<i; j++){
			if(v[j]==k){
				int a=i-j+1;
				while(a--){
					v.pull_back();
				}v.push_back(k);
				continue;
			}
		}v.push_back(k);
	}for(int i=0; i<v; i++){
		cout << v[i] << " ";
	}
	return 0;
}
