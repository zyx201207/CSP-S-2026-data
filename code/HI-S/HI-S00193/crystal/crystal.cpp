#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int m,n,maxx = -1;
	cin>>n>>m;
	vector<long long>a;
	
	for(int i =0;i<n;i++){
		int x;
		cin>>x;
		a.push_back(x);
	}
	bool k = false;
	sort(a.begin(),a.end());
	for(int i = 1;i<n;i++){
		int sum = 0;
		for(int j = i-1;j>=0;j--){
			
			sum+=(a[i]-a[j]);
			if(sum<=m){
				maxx = max(maxx,i-j+1);
			}if(a[i]-a[j]>m){
				k = true;
				break;
			}
		}
		if(k){
			break;
		}
	}
	cout<<maxx;
	return 0;
}

