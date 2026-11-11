#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,a[500042],maxi;
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		int res = 0;
		int cnt = 0;
		for(int j=i;j>=1;j--){
			res += (a[i] - a[j]);
			if(res <= m) cnt++;
			else break;
		}
		if(cnt>maxi) maxi = cnt;
	}	
	cout<<maxi;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
