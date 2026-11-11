#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false),cin.tie(nullptr);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i=0;i<t;++i){
		int n,k;
		cin>>n>>k;
		vector<pair<int ,int>> arr(n-1);
		for(int i=1;i<n;++i){
			cin>>arr[i].first>>arr[i].second;
		}
	}
	
	return 0;}
