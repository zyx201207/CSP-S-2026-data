#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int p=0;p<t;p++){
		int n,d;
		cin>>n>>d;
		vector<int> v(n+1);
		for(int i=0;i<n;i++){
			cin>>v[i];
		}
		cout<<n-d-1;
	}
}
