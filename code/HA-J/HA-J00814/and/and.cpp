#include<bits/stdc++.h>
using namespace std;
int a[200005],n,m;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	int t=0;
	for(int i=2;i<=n;i++){
		if(a[i]<a[i-1])t++;
		if(t==3)cout<<a[i-1];
	}
	return 0;
}
