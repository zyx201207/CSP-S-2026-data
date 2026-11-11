#include <bits/stdc++.h>
using namespace std;
bool cmp(long long x,long long y){
	return x>y;
}
long long a[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin >> n >> m;
	for (int i=0;i<n;i++){
		cin >> a[i];
	}
	sort(a,a+n,cmp);
	long long mid;
	int ind;
	if (n/2==0){
		ind=n/2-1;
	}
	else{
		ind=n/2;
	}
	mid=a[ind];
	int cnt=0;
	for (int i=0;i<ind;i++){
		if (a[i]==mid){
			cnt++;
		}
	}
	bool f=0;
	if (cnt!=0){
		cnt++;
		f=1;
	}
	for (int i=ind+1;i<n;i++){
		if (mid-a[i]<=m){
			cnt++;
			m-=(mid-a[i]);
		}
	}
	if (cnt!=0&&f==0){
		cnt++;
	}
	cout << cnt;
	return 0;
}
