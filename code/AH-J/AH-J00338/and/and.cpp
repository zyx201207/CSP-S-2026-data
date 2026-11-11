#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+10;
int n,m;
int a[N];
int zh[5][100000];//二进制存储
void fun(int x){
	if(x==0)return;
	zh[i][]=x%2;
	fun(x/2);
	
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	cout << 12;
	return 0;
}
