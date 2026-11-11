#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int> w(n),d(n);
	for(int i=0;i<n;i++){
		cin>>w[i];
	}
	sort(w.rbegin(),w.rend());
	d[0]=w[0];
	for(int i=1;i<m;i++){
		d[i]=d[i-1]&w[i];
	}
	cout<<d[m-1];
	return 0;
}

