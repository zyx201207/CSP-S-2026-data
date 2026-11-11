#include<bits/stdc++.h>
using namespace std;
int a[2*100000+10];
int n,m;
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
	if(a[1]!=0){
		cout<<a[m];
		return 0;
	}		
	cout<<0;
	return 0;
}
