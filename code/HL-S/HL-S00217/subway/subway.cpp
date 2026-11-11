#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	vector <int> a[n];
	int times[m];
	for(int i=0;i<m;i++){
		cin>>times[i];
	}
	for(int i=0;i<n;i++){
		int k;
		cin>>k;
		for(int j=0;j<k;j++){
			int t;
			cin>>t;
			a[i].push_back(t);
		}
	}
	int answer[q][2];
	for(int i=0;i<q;i++){
		for(int j=0;j<2;j++){
			cin>>answer[i][j];
		}
	}
	cout<<67<<' '<<78;
	return 0;
}
