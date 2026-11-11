#include<bits/stdc++.h>
using namespace std;
int n,m,k,mx=-1;
int a[200010];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	if(n==m){
		k=a[0];
		for(int i=2;i<=n;i++)
			k&=a[i];
		cout<<k;
		return 0;
	}
	else if(m==1){
		cout<<mx;
		return 0;
	}
	else{
		sort(a+1,a+n+1,cmp);
		cout<<a[m];
	}
}
