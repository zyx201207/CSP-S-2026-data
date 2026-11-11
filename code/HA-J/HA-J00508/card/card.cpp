#include <bits/stdc++.h>
using namespace std;

int main(){
  	freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector<int>lis(n+1);
	for(int i=1;i<=n;i++){
		cin>>lis[i];
	}
	vector<int>s;
	for(int i=1;i<=n;i++){
		int k=0;
		if(s[i]==0)continue;
		for(i){
			if(i==lis[i]){
				k=1;
				
			}
		}
	}
	
	return 0;
} 
