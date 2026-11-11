# include<bits/stdc++.h>
using namespace std;
int n,m;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}	
	sort(a,a+n,cmp);
	long long k=(a[0]&a[1]);
	for(int i=2;i<m;i++){
		k=(k&a[i]);
	}
	cout<<k;
	return 0;
}
