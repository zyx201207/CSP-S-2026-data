#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005][200005],cr;
int main(){
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>cr;
		int t=1;
		while(cr){
			a[i][t]=cr%2;
			cr/=2;
			t++;
		}
	}
	for(int i=1;i<=n;i++){
		cout<<a[1][i];
	}
	return 0;
}
