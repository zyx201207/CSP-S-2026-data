#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	vector<int>v(n);
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	sort(v.begin(),v.end(),greater<int>());
	int sum=v[0];
	for(int i=1;i<m;i++){
		sum=sum&v[i];
	}
	cout<<sum;
	return 0;
}
