#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
	freopen("and.in" ,"r", stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n,m,s;cin>>n>>m;
	int arr[n];
	for(int i=0;i<n;i++)
		cin>>arr[i];
	sort(arr,arr+n);s=arr[n-1];
	for(int i=n-2,x=0;x<m;i++)
		s=s&arr[i],x++;
	cout<<s;
	return 0;
}