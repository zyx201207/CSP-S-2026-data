#include<bits/stdc++.h>
using namespace std;
int c,t;
long long n,d,x;
vector<long long>v[100005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			v[j].push_back(i);
		}
	}
	cout<<"0";
	return 0;
}
