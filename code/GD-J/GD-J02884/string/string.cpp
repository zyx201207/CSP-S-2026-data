#include<bits/stdc++.h>
using namespace std;
vector<char> a;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n; 
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		char y;
		cin>>x>>y;
		while(x--){
			a.push_back(y);
		}
	}
	vector<char> b=a;
	reverse(b.begin(),b.end());
	if(a==b){
		cout<<0;
		return 0;
	}
	long long cnt=0;
	for(int i=0;i<a.size();i++){
		if(a[i]!=b[i]){
			cnt++;
		}
	}
	cout<<cnt/2;
	return 0; 
} 
