#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
const int N=200000+5;
int n,m,a[N],b[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n,cmp);
	cout<<a[m];
	return 0;
}

