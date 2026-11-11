#include<bits/stdc++.h>
using namespace std;
long long a[200010];
long long n,m = 1;
long long sum;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i = 1;i <= n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	if(m==1) cout<<a[1];
	for(int i = 1;i <= m;i++){
		if(i==1) sum = a[i];
		else sum = sum & a[i];
	}
	cout<<sum;
	return 0;
}
