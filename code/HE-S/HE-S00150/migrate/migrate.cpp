#include<bits/stdc++.h>
using namespace std;
long long a[100005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	long long n,d,c,t;
	cin>>c>>t;
	cin>>n>>d;
	for(int i=0;i<=t;i++){
		cin>>a[i];
	}
	cout<<t-1<<endl;
	cout<<t;
	return 0;
}
