#include<bits\stdc++.h>
using namespace std;
long long n,m;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	vector <int> r(n+1);
	for(int i=0;i<n;i++){
		cin>>r[i];
	}
	sort(r.begin(),r.end());
	cout<<r[r.size()-m];
	return 0;
}
