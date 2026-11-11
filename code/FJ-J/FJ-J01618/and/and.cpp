#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n=0,m=0;
	cin>>n>>m;
	vector<int> arr(n,0),brr;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	sort(arr.begin(),arr.end(),greater<int>());
	
	for(int j=0;j<n-m;j++){
		long long sum=-1;
		for(int i=j;i<j+m;i++){
			sum=sum&arr[i];
		}
		brr.push_back(sum);
	}
	sort(brr.begin(),brr.end(),greater<int>());
	cout<<brr[0];
	return 0;
}