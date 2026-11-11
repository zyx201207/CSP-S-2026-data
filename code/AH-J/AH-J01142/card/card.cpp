#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	vector<int>v(n);
	map<int,int>mp;
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	for(int i=1;i<=n;i++){
		vector<int>a;
		for(int j=i-1;j<n;j++){
			if(a.binary_search(v.begin(),v.end(),v[j])){
				
			}
			a.push_back(v[j]);
		}
		for(int j:a){
			mp[j]++;
		}
	}
	for(int i=1;i<+n;i++){
		cout<<mp[i]<<" ";
	}
	return 0;
}
