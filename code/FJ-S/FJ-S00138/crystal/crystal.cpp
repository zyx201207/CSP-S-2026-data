#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	vector <int> a(n+1);
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a.begin(),a.end());
	for (int i=1;i<=m;i++){
		if (a[i]+1==a[i+1]){
			a[i]+=1;
		}
	}
	int b=1;
	for (int j=1;j<=m;j++){
		int c=1;
		for (int i=1;i<=m;i++){
			if (a[i]==a[i+1]){
				c+=1;
			}
		}
		if (c>b){
			b=c;
		}
	}
	cout<<b<<endl;
	return 0;
}
