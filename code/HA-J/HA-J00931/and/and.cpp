#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	if(x<y){
		return true;
	}
	else return false;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	long long a[10000006];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	cout<<a[1];
	
	return 0;
}
