#include<bits/stdc++.h>
using namespace std;
int n,m,x;
vector<long long>ar(n);
bool cmp(vector<long long>ar){
	for(int i=1;i<ar.size();i++){
		if(ar[i]<ar[i-1])return false;
	}return true;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>n>>m;
	vector<long long>ar(n);
	for(int i=0;i<n;i++)cin>>ar[i];
	if(cmp(ar)==true){
		for(int i=1;i<=m;i++)cout<<i<<' ';
		return 0;
	}
	map<int,int> mp;
	mp[ar[n-1]]=n;mp[ar[0]]=1;
	for(int i=0;i<n;i++){
		if(ar[i]!=ar[n-1])mp[ar[i]]++;
	}
	for(int i=1;i<=m;i++)cout<<mp[i]<<' ';
	
	return 0;
} 
