#include <bits/stdc++.h>
using namespace std;
const int N=2e5;
int n,m;
int a[N];
int t=0;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	cout<<a[m-1];
	return 0;
}
