#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100000000];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n,cmp);
	if(m==1){
		cout<<a[1];
		return 0;
	}
	cout<<a[m];
	return 0;
}
