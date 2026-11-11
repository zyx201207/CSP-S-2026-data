#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n;
	long long m;
	cin >> n >> m;
	vector<long long> a(n);
	for(int i=0;i<n;i++)cin >> a[i];
	sort(a.begin(),a.end());
	reverse(a.begin(),a.end());
	int Max=-1;
	for(int i=0;i<n;i++){
		int cnt=1;
		long long x=m;
		for(int j=i+1;j<n;j++){
			if(a[i]-a[j]<=x){
				cnt++;
				x-=a[i]-a[j];
			}
		}
		Max=max(Max,cnt);
	}
	cout << Max << endl;
	return 0;
}
