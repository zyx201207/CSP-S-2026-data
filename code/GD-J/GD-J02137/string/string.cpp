#include<bits/stdc++.h>
using namespace std;
vector<int> sz;
vector<char> zm;
vector<char> zz;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int w;
		cin>>w;
		sz.push_back(w);
		char x;
		cin>>x;
		zm.push_back(x);
	}
	for(int i=0;i<n;i++){
		for(int c=0;c<sz[i];c++){
			zz.push_back(zm[i]);
		}
	}
	long long he,ans;
	ans=0;
	he=zz.size();
	for(int i=0;i<=he/2-1;i++){
		if(zz[i]!=zz[he-1-i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
} 
