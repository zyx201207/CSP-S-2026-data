#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>n;
	cout<<(n-1)%7<<"\n"<<n%7;
	return 0;
}
