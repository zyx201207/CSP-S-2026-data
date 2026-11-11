#include <bits/stdc++.h>
using namespace std;

int n,m,pos[35],los = 0;
long long a[200005];

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	vector <int> wn[35],pans;
	cin>>n>>m;
	
	for (int i=1,x;i<=n;i++) {   
		cin>>x;
		a[i] = x;
		int p = 0;
		while (x != 0){
			if ((x&1) == 1){
				pos[p]++;
				wn[p].push_back(i);
			}
//			cout<<"p:"<<p<<" pos[p]:"<<pos[p]<<" x:"<<x<<'\n';
			x = x >> 1;
			p++;
		}
	}
//	for (int i=0;i<=30;i++) {
//		cout<<pos[i]<<' ';
//	}

	int tmp1 = -1;
	for (int i=30;i>=0;i--){
		if (pos[i] >= m) {
			tmp1 = i;
			break;
		}
	}
	int tmp2 = 0;
	for (int id : wn[tmp1]) {
		pans.push_back(id);
		tmp2++;
	}
	los = tmp2;
	bool flag = 0;
	while (los > m){
		
//		cout<<"pans: ";
//		for (int id:pans){
//			cout<<a[id]<<' ';
//		}
//		cout<<'\n';
		flag = 0;
		memset(pos,0,sizeof pos);
		for (int i=0;i<35;i++) wn[i].resize(1);
		memset(wn,0,sizeof wn);
		for (int id : pans) {
			long long x = a[id];
			int p = 0;
			while (x != 0) {
				if ((x & 1) == 1){
					pos[p]++;
					wn[p].push_back(id);
				}
				x = x >> 1;
				p++;
			}
		}
		
//		for (int i=0;i<=30;i++) cout<<pos[i]<<' ';
//		cout<<'\n';
		
		for (int i=tmp1-1;i>=0;i--){
			if (pos[i] >= m){
				tmp1 = i;
				flag = 1;
				break;
			}
		}
		
		if (!flag) break;
		int tmp2 = 0;
		pans.clear();
		for (int id : wn[tmp1]) {
			pans.push_back(id);
			tmp2++;
		}
		
		los = tmp2;
	}
//	cout<<los<<'\n';
	long long ans = a[pans[0]];
	for (int id:pans){
//		cout<<a[id]<<' ';
		ans = ans & a[id];
	}
	cout<<ans;
}
