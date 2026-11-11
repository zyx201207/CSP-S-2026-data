#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],num,t;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n,cmp);
	num=a[1];
	for(int i=1;i<=m;i++){
		t=num & a[i];
		if((t==0) and (m+1<=n)){
			m++;
			continue;
		}
		num=num & a[i];
	}
	cout<<num;
	return 0;
}
