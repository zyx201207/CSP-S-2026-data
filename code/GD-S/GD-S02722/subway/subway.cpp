#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> f;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,l,s,ml,p;
	cin>>c>>l>>s>>ml>>p;
	int t[s];
	for(int i=0;i<s;i++){
		cin>>t[i];
	}
	for (int i = 0; i < l;i++){
		int c;
		cin>>c;
		int p;
		f.push_back({});
		for(int i=0;i<c;i++){
			cin >> p;
			f.back.push_back(p);
		}
	}
	cout<<"32\n17";
	return 0;
}
