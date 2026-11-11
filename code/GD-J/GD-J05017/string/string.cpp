#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	vector<char> v;
	for(int i=1;i<=n;i++){
		int num;
		char c;
		cin>>num>>c;
		for(int i=1;i<=num;i++){
			v.push_back(c);
		}
	}
	int s=v.size();
	long long ans=0;
	for(int i=0;i<s/2;i++){
		if(v[i]!=v[n+1-i]) ans++;
	}
	cout<<ans;
	return 0;
}
