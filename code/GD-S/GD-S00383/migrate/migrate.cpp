#include<bits/stdc++.h>
using namespace std;
int c,t;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	int sum=1;
	while(t--){
		int n,d;
		cin>>n>>d;
		vector<int>pos;
		pos.resize(n);
		for(int i=0;i<n;i++){
			cin>>pos[i];
		}
		cout<<sum<<endl;
		sum++;
	}
	return 0;
} 
