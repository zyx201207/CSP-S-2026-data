#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int q;
	cin>>q;
	string p;
	vector<string>v;
	int ans=0;
	for(int i=1;i<=q;i++){
		int x;
		cin>>x;
		string c;
		cin>>c;
		p=c;
		for(int j=1;j<=x;j++){
			v.push_back(p);
		}
	} 
	vector<string>m;
	for(int i=v.size()-1;i>=0;i--){
		m.push_back(v[i]);
	}
	
	cout<<ans;
	return 0;
}
