#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n,m;
	cin>>n>>m;
	
	int arr[n+5];
	for(int i=0;i<n;++i){
		cin>>arr[i];
	}
	cout<<arr[n-1];
	return 0;
}