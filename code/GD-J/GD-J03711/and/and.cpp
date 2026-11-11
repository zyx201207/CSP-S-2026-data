#include <bits/stdc++.h>
using namespace std;
int sum = 0;
int ande(int x,int y){
	long long a,b;
	while(x>1){
		x/=2;
	}
}
int t(int x,int y){
	if(x>y){
		return y;
	}else{
		return x;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[200010];
	cin >> n >> m;
	for(int i =1;i<=n;i++){
		cin >> a[i];
	}
	for(int i = 1;i<=m;i++){
		
	}
	for(int i = 1;i<=n;i++){
		sum = max(sum,t(a[i],a[i+1]));
	}
	cout << sum;
	return 0;
}
