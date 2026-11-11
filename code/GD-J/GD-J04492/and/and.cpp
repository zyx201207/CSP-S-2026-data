#include<bits/stdc++.h>
using namespace std;
int a[20005];
bool cmp(int x,int y){
	return x>y;
}
int er(int x){
	int sum=0;
	while(x>0){
		sum=sum+x%2*10;
	}
	return sum;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,k=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=0;i<=m;i++){
		k=er(k)&er(a[i]);
	}
	cout<<k<<endl;
	return 0;
}
