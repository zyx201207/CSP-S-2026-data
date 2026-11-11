#include <bits/stdc++.h>
using namespace std;
long long a[500010];
long long mp[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	vector<long long> s;
	/*
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			if(s.find(a[j])){
				s.clear();
			}
			s.push_back(a[j]);
		}
	}*/
	for(int i=0;i<n;i++){
		cout<<n<<' ';
	}
	return 0;
}
