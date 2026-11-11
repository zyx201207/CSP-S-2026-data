#include<bits/stdc++.h>

using namespace std;

int main(){	
	int n;
	int m;
	cin>>n>>m;
	int an[100000];
	int num[100000];
	for(int i = 0;i<n;i++){
			cin>>an[i];
	}
	if(m==1){
		int maxx = -1000000;
		for(int i = 0;i<n;i++){
			maxx = max(an[i],maxx);
		}
		cout<<maxx;
		return 0;
	}
	else{
		for(int i = 0;i<n;i++){
			int ans = 0;
			for(int j = i;j<i+m-1;j++){
				ans += int(an[j]||an[j+1]);
			}
			num[i] = ans;
		}
		int maxx = -1000000;
		for(int i = 0;i<n;i++){
			maxx = max(num[i],maxx);
		}
		cout<<maxx;
		return 0;
	}
}

