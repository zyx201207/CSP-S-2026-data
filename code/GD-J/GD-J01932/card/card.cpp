#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	vector<int> arr;
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		arr.push_back(a);
	}
	
	for(int i=2;i<=m;i++) cout<<arr[i]<<" ";
	
	return 0;
}
