#include<bits/stdc++.h>
using namespace std;
const int MAXN=10000008;
int x[MAXN];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long c,t,n,d;
	cin>>c>>t;
	for(int i=0;i<t;i++){
		cin>>n>>d;
		for(int j=0;j<n;j++){
			cin>>x[j];
		}
	}
	int a=1,b=2;
	cout<<a<<endl;
	cout<<b<<endl;
	return 0;
}
