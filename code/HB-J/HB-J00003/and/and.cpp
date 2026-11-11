#include<bits/stdc++.h>
using namespace std;
vector<bool> g_b(int num){
	vector<bool>ans(30);
	int pos=0;
	while(num>0){
		ans[pos]=num%2;
		num/=2;
		pos++;
	}
	return ans;
}
bool cmp(pair<string,int>p1,pair<string,int>p2){
	return p1.first<p2.first;
}
string g_s(int num){
	string s;
	vector<bool>ans(30);
	ans=g_b(num);
	for(int i=29;i>=0;i--){
		if(ans[i]==false)s.push_back(i+'A');
	}
	return s;
}
int main(){
	freopen("ans.in","r",stdin);
	freopen("ans.out","w",stdout);
	int n,m,ans;
	cin>>n>>m;
	vector<int>v(n+1);
	vector<pair<string,int>>p;
	for(int i=0;i<n;i++){
		cin>>v[i];
		p.push_back({g_s(v[i]),i});
	}
	sort(p.begin(),p.end(),cmp);
	ans=v[p[0].second];
	for(int i=0;i<m;i++){
		ans=ans&v[p[i].second];
	}
	cout<<ans;
	return 0;
}
