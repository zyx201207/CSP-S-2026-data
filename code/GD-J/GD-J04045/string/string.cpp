#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	vector<pair<int,char>>v;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		char a;
		cin>>a;
		v.push_back({x,a});
	}
	int i=0;
	int j=v.size()-1;
	long long need=0;
	while(i<j){
		if(v[i].first==v[j].first){
			if(v[i].second!=v[j].second) need+=v[i].first;
			i++,j--;
		}
		else if(v[i].first<v[j].first){
			if(v[i].second!=v[j].second) need+=v[i].first;
			v[j].first-=v[i].first;
			i++;
		}
		else{
			if(v[i].second!=v[j].second) need+=v[j].first;
			v[i].first-=v[j].first;
			j--;
		}
	}
	cout<<need;
	return 0;
}
