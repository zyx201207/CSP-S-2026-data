#include<bits/stdc++.h>
using namespace std;
bool sr(int x,int y){
	return x>=y;
}
int main(){
	int n,m;
	long long a[200005],mmax=-1e9+10;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,sr);
	cout<<a[m];
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	return 0;
} 
