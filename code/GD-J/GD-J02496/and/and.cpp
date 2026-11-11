#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<long long>a,z;
void andd(int x,long long sum){
	if(x==m){
		z.push_back(sum);
		return;
	}
	for(int i=x+1;i<=n;i++){
		andd(x+1,sum&a[i-1]);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	a.resize(n);
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a.begin(),a.end());
	andd(1,a[0]);
	sort(z.begin(),z.end());
	cout<<z[z.size()-1];
	return 0;
}

