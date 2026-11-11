#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	int c=0,o=0;
	while(a){
		c+=a%2;
		a/=2;
	}
	while(b){
		o+=b%2;
		b/=2;
	}
	return c<o;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,i,j;
	long long ma=-1;
	cin>>n>>m;
	vector<int> v(n);
	for(i=0;i<n;i++) scanf("%d",&v[i]);
	sort(v.begin(),v.end(),cmp);
	for(i=n-1;i>=m-1;i--){
		long long inf=v[i];
		for(j=i-1;j>i-m;j--) inf=inf&v[j];
		ma=ma>inf?ma:inf;
	}
	cout<<ma;
	return 0;
}
