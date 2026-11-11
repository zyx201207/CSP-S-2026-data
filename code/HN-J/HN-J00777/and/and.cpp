#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200020];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	if(m==1)cout<<a[0];
	else cout<<a[m-1];
	return 0;
}

