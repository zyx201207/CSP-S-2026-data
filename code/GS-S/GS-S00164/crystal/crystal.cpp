#include<bits/stdc++.h>
using namespace std;
int df[5005];
int n,m;
int h = 10000;
int ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> df[i];
	}
	
	sort(df+1,df+n+1);
	for(int i = 1;i < n;i++){
		for(int j = i+1;j <= n;j++){
			int pro = 0;
			for(int k = i;k < j;k++){
				pro += df[j] - df[k];
			}		
			if(pro <= m) ans = max(ans,j-i+1);
		}
	}
	cout << ans;
	return 0;
}

