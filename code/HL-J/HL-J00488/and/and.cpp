#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
const int M=2e5+5;
int x[M];
int cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>x[i];
	}
	sort(x,x+n,cmp);
	cout<<x[m-1];
}
