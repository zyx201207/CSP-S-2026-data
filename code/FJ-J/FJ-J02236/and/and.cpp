#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010];
int q(int x,int y){
	if(x>y)return x>y;
	return x<y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,q);
	cout<<a[3];
}
