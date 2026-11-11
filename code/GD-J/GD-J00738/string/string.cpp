#include<bits/stdc++.h>
using namespace std;
long long t;
vector<char>v;
long long ans;
int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>t;
	while(t--){
		int l;
		char a;
		cin>>l>>a;
		for(int i=1;i<=l;i++){
			v.push_back(a);
		}
	}
	int mid=(v.size())/2;
	for(int i=0;i<mid;i++){
		if(v[i]!=v[v.size()-1-i]) ans++;
	}
	cout<<ans;
	return 0;
}
