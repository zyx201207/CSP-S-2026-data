#include <bits/stdc++.h>
using namespace std;
int n,m,c[100005];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>c[i];
	}
	sort(c,c+n,cmp);
	cout<<c[m-1];
	return 0;
}
