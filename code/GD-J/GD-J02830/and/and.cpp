#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],k=INT_MAX;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(m==1){
		for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	cout<<a[1];
	return 0;
	}else {
		for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=m;i++){
		k=k&a[i];
		//cout<<a[i]<<" ";
	}
	cout<<k;
	}
	return 0;
}
