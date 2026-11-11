#include <bits/stdc++.h>
using namespace std;

int main(){
  	freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int> lis(n+1);
	for(int i=1;i<=n;i++){
		cin>>lis[i]; 
	}
	int max_=-1;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int k=lis[j]&&lis[i];
			max_ = max(max_,k);
		}
	}
	/*
	4 2
 3 15 12 12
	*/
	cout<<max_;
	
	
	return 0;
} 
