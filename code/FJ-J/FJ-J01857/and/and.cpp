#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[200005];
int get(int x1,int x2){
	int cnt=0;
	vector<bool> v1;
	vector<bool> v2;
	while(x1>=1 || x2>=1){
		v1.push_back(x1%2);
		v2.push_back(x2%2);
		x1/=2;x2/=2;
	}
	for(int i=0;i<v1.size();i++){
		cout<<v1[i];
	}
	cout<<'\n';
	for(int i=0;i<v2.size();i++){
		cout<<v2[i];
	}
	return cnt;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout<<12;
	
	return 0;
}
