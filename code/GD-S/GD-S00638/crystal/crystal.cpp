#include <bits/stdc++.h>
using namespace std;
int n,m,ans;
int a[5000005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.ans","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int l=1;
	while(l*(l+1)<=m){
		l++;
	}
	l++;
	cout<<l<<endl;
	return 0;
}

