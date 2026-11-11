#include <bits/stdc++.h>
using namespace std;
vector<int> arr;
int zhuomian[300005];
int mm[300005];
int n,m;

int a;
int zhuomian_i=0;
int f(int k) {
	int cnt=0;
	for(int i=0; i<=zhuomian_i; i++) {
		if(zhuomian[i]==k) {
			cnt=i;
		}
	}
	return cnt;
}
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=0; i<n; i++) {
		cin>>a;
		arr.push_back(a);
	}

	for(int i=0; 0<=n; i++) {
		int dc=arr[i];
		int panduan=f(dc);
		if(panduan!=0) {
			for(int j=panduan; j<=zhuomian_i; j++) {
				zhuomian[j]=0;
			}
			zhuomian[zhuomian_i]=dc;
		} else {
			zhuomian_i++;
			zhuomian[zhuomian_i]=dc;
		}
		for(int j=0; j<=zhuomian_i; j++) {
			mm[zhuomian[zhuomian_i]]++;
		}
	}
	for(int i=1; i<=n; i++) {
		cout<<mm[i]<<" ";
	}
	return 0;
}
