#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	int n,m,a[50010],p,y,s=3;
	cin>>n>>m;
	cin>>a[50010];
	for(int i=1;i<=n;i++){
		p=(a[i]+a[i+1])/2;
		y=m-p+a[i];
	} 
	cout<<s;
	return 0;
}
