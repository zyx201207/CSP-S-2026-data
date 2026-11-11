//GZ-J00677 遵义市第十九中学 李俊希 
#include<bits/stdc++.h>
using namespace std;
struct node{
	int x;
}a[201000];
int LLL(node a,node b){
	return a.x>b.x;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].x;
	}
	sort(a+1,a+n+1,LLL);
	
	
	cout<<a[m].x;
	

	
	return 0;
}
